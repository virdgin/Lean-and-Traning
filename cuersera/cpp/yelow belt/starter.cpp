#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType
{
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query
{
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream &operator>>(istream &is, Query &q)
{
  // Реализуйте эту функцию
  string operation_code;
  is >> operation_code;

  if (operation_code == "NEW_BUS")
  {
    q.type = QueryType::NewBus;
    is >> q.bus;
    size_t stop_count = 0;
    is >> stop_count;
    q.stops.resize(stop_count);
    for (auto &item : q.stops)
    {
      is >> item;
    }
  }
  else if (operation_code == "BUSES_FOR_STOP")
  {
    q.type = QueryType::BusesForStop;
    is >> q.stop;
  }
  else if (operation_code == "STOPS_FOR_BUS")
  {

    q.type = QueryType::StopsForBus;
    is >> q.bus;
  }
  else if (operation_code == "ALL_BUSES")
  {
    q.type = QueryType::AllBuses;
  }
  return is;
}

struct BusesForStopResponse
{
  // Наполните полями эту структуру
  vector<string> buses_to_stops;
};

ostream &operator<<(ostream &os, const BusesForStopResponse &r)
{
  if (r.buses_to_stops.empty())
  {
    os << "No stop";
  }
  else
  {
    for (const auto &i : r.buses_to_stops)
    {
      os << i << " ";
    }
  }
  return os;
}

struct StopsForBusResponse
{
  string bus;
  vector<pair<string, vector<string>>> stop_for_bus;
  // Наполните полями эту структуру
};

ostream &operator<<(ostream &os, const StopsForBusResponse &r)
{
  if (r.stop_for_bus.empty())
  {
    os << " No bus";
  }
  else
  {
    bool first = true;
    for (const auto &SaB : r.stop_for_bus)
    {
      if (!first)
      {
        os << endl;
      }
      first = false;
      os << "Stop " << SaB.first << ":";
      if (SaB.second.size() == 1)
      {
        os << " no interchange";
      }
      else
      {
        for (const auto &_bus : SaB.second)
        {
          if (_bus != r.bus)
          {
            os << " " << _bus;
          }
        }
      }
    }
  }
  // Реализуйте эту функцию
  return os;
}

struct AllBusesResponse
{
  map<string, vector<string>> all_bus;
  // Наполните полями эту структуру
};

ostream &operator<<(ostream &os, const AllBusesResponse &r)
{
  if (r.all_bus.empty())
  {
    os << "No buses";
  }
  else
  {
    bool first = true;
    for (const auto &BaS : r.all_bus)
    {
      if (!first)
      {
        os << endl;
      }
      first = false;
      os << "Bus " << BaS.first << ":";
      for(const auto& _stop: BaS.second){
        os<<" "<<_stop;
      }
    }
  }
  // Реализуйте эту функцию
  return os;
}

class BusManager
{
public:
  void AddBus(const string &bus, const vector<string> &stops)
  {
  stops_bus.insert(make_pair(bus,stops));
    for (const auto& stop: stops){
      stops_bus[stop].push_back(bus);
    }
    // Реализуйте этот метод
  }

  BusesForStopResponse GetBusesForStop(const string &stop) const
  {
    if(stops_bus.count(stop)==0){
      return BusesForStopResponse{vector<string>()};
    }
    else return BusesForStopResponse{stops_bus.at(stop)};
    // Реализуйте этот метод
  }

  StopsForBusResponse GetStopsForBus(const string &bus) const
  {
    vector<pair<string, vector<string>>> finish;
    if(buses_stop.count(bus)>0){
      for(const auto& stop: buses_stop.at(bus)){
      finish.push_back(make_pair(stop,stops_bus.at(stop)));
      }
    }
    return StopsForBusResponse{bus,finish};
    // Реализуйте этот метод
  }

  AllBusesResponse GetAllBuses() const
  {
    return AllBusesResponse{stops_bus};
    // Реализуйте этот метод
  }
  private:
  map<string,vector<string>> stops_bus;
  map<string,vector<string>> buses_stop;
};

// Не меняя тела функции main, реализуйте функции и классы выше

int main()
{
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i)
  {
    cin >> q;
    switch (q.type)
    {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}
