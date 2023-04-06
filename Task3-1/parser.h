#pragma once
#include <regex>
#include <QString>
#include <set>
#include <algorithm>
#include <iostream>
#include <thread>
#include <QDebug>
using namespace std;
class parser {
private:
    vector<string> classes;
    vector<string> structs;
    vector<string> input;
    QString inputStr;
    vector<pair<string, pair<size_t, size_t>>> variables;
    vector<pair<pair<string, string>, pair<size_t, size_t>>> prototypes;
    vector<string> arrays;
    set<string> types {
            "auto",
            "void",
            "bool",
            "char",
            "unsigned char",
            "short",
            "int",
            "long long",
            "unsigned short",
            "unsigned int",
            "unsigned long",
            "unsigned long long",
            "size_t",
            "float",
            "double"
    };
    vector<int> branchLevel;

    void variablesSearch();
    void classesSearch();
    void arraysSearch();
    void prototypesSearch();
    string typesToLine();
public:
    explicit parser(const vector<string>&);
    vector<pair<string, pair<size_t, size_t>>> logicErrors();
    vector<pair<string, pair<size_t, size_t>>> variablesChanges();
    pair<size_t, size_t> coordinates(const string&, size_t);
    pair<vector<pair<string, pair<size_t, size_t>>>, size_t> overloadedFuncCount();
    void countBranсh(size_t);
    void findBranches();
    [[nodiscard]] vector<int> get_branchesCount();
    [[nodiscard]] set<string> get_types();
    [[nodiscard]] vector<string> get_classes();
    [[nodiscard]] vector<string> get_structs();
    [[nodiscard]] vector<pair<string, pair<size_t, size_t>>> get_variables() const;
    [[nodiscard]] vector<string> get_arrays() const;
    [[nodiscard]] const vector<pair<pair<string, string>, pair<size_t, size_t>>>& get_prototypes() const;
};
void parser::variablesSearch() {
    for (size_t i = 0; i < input.size(); ++i) {
        string typeRegex;
        typeRegex = (R"(((const\s)?()" + typesToLine() + R"()\**(<.*>)*\s+(\**\s*\w+(\s=\s[-+]?(?:\d+|\d*.\d+)(?:[eE][-+]?\d+)?\b)*(,*\s*))*(;)))");
        regex r(typeRegex);
        smatch typeRes;
        if (regex_search(input[i], typeRes, r))
            variables.emplace_back(typeRes[0], coordinates(typeRes[0], i));
    }
}
void parser::classesSearch() {
    for (const auto &i: input) {
        string src(R"((class|struct)\s+(\w+)\s*\{)");
        regex r(src);
        smatch res;
        if (regex_search(i, res, r)) {
            types.insert(res[2]);
            if (res[1] == "class")
                classes.emplace_back(res[2]);
            else if (res[1] == "struct")
                structs.emplace_back(res[2]);
        }
    }
}
void parser::arraysSearch()
{
    for (const auto& inputLine : input)
    {
        string typeRegex;
        typeRegex = "((" + typesToLine() + R"(\**)\s*(\w+\[\d+\]+)\s*((\{(.)*\})*)(;)))";
        regex r(typeRegex);
        smatch typeRes;
        if (regex_search(inputLine, typeRes, r))
        {
            arrays.emplace_back(typeRes[0]);
        }
    }
}
parser::parser(const vector<string>& input)
    : input(input)
{
    thread t1(&parser::classesSearch, this);
    thread t2(&parser::variablesSearch, this);
    thread t3(&parser::arraysSearch, this);
    thread t4(&parser::prototypesSearch, this);
    branchLevel.resize(input.size() + 1);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
}
void parser::prototypesSearch()
{
    for (size_t i = 0; i < input.size(); ++i)
    {
        string typeRegex;
        string typeLine = typesToLine();
        typeRegex = "(const\\s)?(" + typeLine + R"()&*\s*&*(\w+\:\:)*(\w+)(\s*)(\(((const\s)?()" + typeLine + R"()(&*\.*\s*&*\.*\w*)(\s=\s[-+]?(?:\d+|\d*.\d+)(?:[eE][-+]?\d+)?\b)*,*\s*)*\)))";
        regex r(typeRegex);
        smatch typeRes;
        if (regex_search(input[i], typeRes, r))
        {
            prototypes.emplace_back(make_pair(typeRes[0], typeRes[4]), coordinates(typeRes[0], i));
        }
    }
}
string parser::typesToLine()
{
    string typesLine;
    auto it = types.begin();
    for (size_t i = 0; i < types.size(); ++i)
    {
        typesLine += *it++;
        if (i != types.size() - 1)
        {
            typesLine.push_back('|');
        }
    }
    return typesLine;
}
vector<pair<string, pair<size_t, size_t>>> parser::logicErrors()
{
    vector<pair<string, pair<size_t, size_t>>> errors;
    for (size_t i = 0; i < input.size(); ++i)
    {
        string reg(R"(((while|if|else if)\s*\((true|false)\))|(for\s+\(\s*((\w+\s+)*\w+(\s=\s.+)*)*;\s*;.*\)))");
        regex r(reg);
        smatch res;
        if (regex_search(input[i], res, r))
        {
            errors.emplace_back(res[0], coordinates(res[0], i));
        }
    }
    return errors;
}
vector<pair<string, pair<size_t, size_t>>> parser::variablesChanges()
{
    vector<pair<string, pair<size_t, size_t>>> changes;
    const regex reg(R"(((\+\+|--)\w+)|(\w+(\+\+|--))|(\w+\s(=|\+=|-=)\s*([^\s\)])+\s*;))");
    for (size_t i = 0; i < input.size(); ++i)
    {
        smatch res;
        if (regex_search(input[i], res, reg))
        {
            changes.emplace_back(res[0].str(), coordinates(res[0].str(), i));
        }
    }
    return changes;
}
set<string> parser::get_types()
{
    return types;
}
vector<string> parser::get_classes()
{
    return classes;
}
vector<string> parser::get_structs()
{
    return structs;
}
pair<size_t, size_t> parser::coordinates(const string& match, size_t ind)
{
    const size_t row = ind + 1;
    const size_t col = input[ind].find(match) + 1;
    return { row, col };
}
bool IsUnique(const vector<pair<pair<string, string>, pair<size_t, size_t>>>& vec, size_t ind)
{
    for (size_t i = 0; i < vec.size(); ++i)
    {
        if (i == ind)
        {
            continue;
        }
        if (vec[i].first.second == vec[ind].first.second)
        {
            return false;
        }
    }
    return true;
}
bool IsChecked(const vector<pair<pair<string, string>, pair<size_t, size_t>>>& vec, size_t ind)
{
    for (size_t i = 0; i < ind; ++i)
    {
        if (vec[i].first.second == vec[ind].first.second)
        {
            return true;
        }
    }
    return false;
}
pair<vector<pair<string, pair<size_t, size_t>>>, size_t> parser::overloadedFuncCount()
{
    size_t count = 0;
    vector<pair<string, pair<size_t, size_t>>> crd_first;
    for (size_t i = 0; i < prototypes.size(); ++i)
    {
        if (!IsChecked(prototypes, i) && !IsUnique(prototypes, i))
        {
            ++count;
        }
    }
    for (size_t i = 0; i < prototypes.size(); ++i)
    {
        if (!IsUnique(prototypes, i))
        {
            crd_first.emplace_back(prototypes[i].first.first, make_pair(prototypes[i].second.first, prototypes[i].second.second));
        }
    }
    return make_pair(crd_first, count);
}
void parser::countBranсh(size_t i)
{
    const regex r(R"(((while|if|else if|else)\s?\(.+\)\s*\{)|(for\s?\(.+\)\s*\{))");
    smatch res;
    if (regex_search(input[i], res, r))
    {
        branchLevel[i]++;
        size_t j = i + 1;
        while (coordinates("}", j).second != coordinates(res[0], i).second && j < input.size() - 1)
        {
            countBranсh(j);
            ++j;
        }
    }
}
void parser::findBranches()
{
    for (size_t i = 0; i < input.size(); ++i)
    {
        countBranсh(i);
    }
}
vector<int> parser::get_branchesCount()
{
    return branchLevel;
}
vector<pair<string, pair<size_t, size_t>>> parser::get_variables() const
{
    return variables;
}
vector<string> parser::get_arrays() const
{
    return arrays;
}
const vector<pair<pair<string, string>, pair<size_t, size_t>>> &parser::get_prototypes() const
{
    return prototypes;
}
