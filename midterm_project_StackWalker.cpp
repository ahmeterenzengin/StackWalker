#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
struct Movement
{
  string direction;
  double distance;
  Movement(string d, double dist) : direction(d), distance(dist) {}
};
string directionFormat(string data)
{
  transform(data.begin(), data.end(), data.begin(), ::tolower);
  if (!data.empty())
  {
    data[0] = toupper(data[0]);
  }
  return data;
}
string invertDirection(string dir)
{
  if (dir == "North")
  {
    return "South";
  }
  else if (dir == "South")
  {
    return "North";
  }
  else if (dir == "East")
  {
    return "West";
  }
  else if (dir == "West")
  {
    return "East";
  }
  else
  {
    return "Unknown direction";
  }
}
class routeTracker
{
private:
  stack<Movement> route;
  double x, y;
  void updateCoordinates(string dir, double dist)
  {
    if (dir == "North")
      y += dist;
    else if (dir == "South")
      y -= dist;
    else if (dir == "East")
      x += dist;
    else if (dir == "West")
      x -= dist;
  }

public:
  routeTracker() : x(0.0), y(0.0) {}
  void addMovement(string dir, double dist)
  {
    route.push(Movement(dir, dist));
    updateCoordinates(dir, dist);
    cout << "Move added. New location X: " << x << ", Y: " << y << endl;
  }
  void backTrack()
  {
    if (route.empty())
    {
      cout << "You are already at the start or route is empty" << endl;
      return;
    }
    cout << "The backtrack has begun" << endl;
    while (!route.empty())
    {
      Movement lastMove = route.top();
      string backdirection = invertDirection(lastMove.direction);
      cout << "Command: To " << backdirection << " direction " << lastMove.distance << "meter move." << endl;
      updateCoordinates(backdirection, lastMove.distance);
      cout << "Current location is X: " << x << "Y: " << y << endl;
      route.pop();
    }
    cout << "Succesfully you are in start(0,0)" << endl;
  }
  void showStatus()
  {
    cout << "Status: You have did " << route.size() << " movement so far.This is the current status ( X :" << x << " Y : " << y << " )" << endl;
  }
};
int main()
{
  routeTracker tracker;
  int choice;
  cout << "======== Route Tracker System ========" << endl;
  while (true)
  {
    tracker.showStatus();
    cout << "\n1. Add Movement\n2. Backtrack\n3. Exit\n What's your choice? : \n";
    cin >> choice;
    if (choice == 1)
    {
      string dir;
      double dist;
      cout << "Direction (North/South/East/West): ";
      cin >> dir;
      dir = directionFormat(dir);
      cout << "Distance (meter): ";
      cin >> dist;
      tracker.addMovement(dir, dist);
    }
    else if (choice == 2)
    {
      tracker.backTrack();
    }
    else if (choice == 3)
    {
      cout << "You are exiting the Route Tracker , Goodbye!" << endl;
      break;
    }
  }
}
