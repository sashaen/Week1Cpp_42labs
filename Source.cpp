#include<iostream>
#include<fstream>
#include<cstring>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<deque>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

//to read json from json file
// ifstream f("example.json");
// json data = json::parse(f);

// Creating Json Object
int main()
{

    //Serializing into a output file
    std::ofstream f("serialized_output.json");

    // Creating a JSON Object 
    json j1 = {
      {"pi", 3.141},
      {"happy", true},
      {"name", "Niels"},
      {"nothing", nullptr},
      {"answer", {
        {"everything", 42}
      }},
      {"list", {1, 0, 2}},
      {"object", {
        {"currency", "USD"},
        {"value", 42.99}
      }}
    };

    // serialization of json to string using json.dump()
    std::string s = j1.dump();
    std::cout << s << std::endl;

    //Converting STL Containers to json objects
    std::vector<std::uint8_t> v = { 't', 'r', 'u', 'e' };
    json j_vector = json::parse(v.begin(), v.end());
    //f<<j_vector;
    std::cout << j_vector << std::endl;

    // std::unordered_map<std::string,std::uint8_t> c_map{ {"Hello",'1'},{"Hi",'2'},{"Welcome",'3'}};
    // json j_map = json::parse(c_map);

    std::unordered_set<std::string> c_uset{ "one", "two", "three", "four", "one" };
    json j_uset(c_uset);
    f << j_uset;
    std::cout << j_uset << std::endl;

    std::unordered_multiset<std::string> c_umset{ "one", "two", "one", "four" };
    json j_umset(c_umset);
    //f<<j_umset;
    std::cout << j_umset << std::endl;

    std::deque<std::uint8_t> c_deque = { '1', '2', '4','5','7','9' };
    json j_deque = json::parse(c_deque.begin(), c_deque.end());
    //f<<j_deque;
    std::cout << j_deque << std::endl;

    // Deserialize a string to json object

    std::cout << "Deserialization : ----------";
    // create object from string literal
    json j = "{ \"happy\": true, \"pi\": 3.141 }"_json;

    auto j2 = R"(
  {
    "happy": true,
    "pi": 3.141
  }
)"_json;

    std::cout << j << std::endl << j2;
    return 0;
}
