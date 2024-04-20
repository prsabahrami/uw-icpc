/**
 * CTU Open 2017
 * Problem Solution: Equinox Roller Coaster
 *
 * Time complexity O(n*sqrt(n)*log(n)).
 * For every candidate for the top-left corner, try either all candidates for
 * the bottom-left or the top-right corner and check if the other two corners
 * are present.
 * @author Josef Cibulka
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

struct Point
{
  int x,y;
};

bool operator< (const Point &p1, const Point &p2)
{
  if (p1.x != p2.x)
    return (p1.x < p2.x);
  else 
    return (p1.y < p2.y);
}

// Points pt1 and pt2 differ in a single coordinate.
// Returns true iff pts form the square containing both pt1 and pt2 and having
// pt1 as the corner with the smallest coordinates. 
bool test_pair(Point &pt1, Point &pt2, set<Point> &pts)
{
  if(pt1.x > pt2.x || pt1.y > pt2.y)
    return false;
  int x1 = pt1.x;
  int y1 = pt1.y;
  int x2 = (pt1.x != pt2.x ? pt2.x : x1 + (pt2.y - pt1.y));
  int y2 = (pt1.y != pt2.y ? pt2.y : y1 + (pt2.x - pt1.x));
  return (pts.find(Point{x1,y2}) != pts.end() &&
          pts.find(Point{x2,y1}) != pts.end() &&
          pts.find(Point{x2,y2}) != pts.end());
}

int main(void)
{
  int size;
  while (cin >> size)
  { 
    // The set of all points.
    set<Point> ptset;
    // Lists of points grouped by x-coordinate (ptx) and y-coordinate (pty).
    map<int, vector<Point> > ptx; 
    map<int, vector<Point> > pty;
    for(int i=0; i<size; ++i)
    {
      int x,y;
      cin >> x >> y;
      Point newpt {x,y};
      ptset.insert(newpt);
      auto iterx = ptx.find(x);
      if(iterx == ptx.end())
      {
        ptx.insert(std::make_pair(x, vector<Point>()));
        iterx = ptx.find(x);
      }      
      iterx->second.push_back(newpt);
      auto itery = pty.find(y);
      if(itery == pty.end())
      {
        pty.insert(std::make_pair(y, vector<Point>()));
        itery = pty.find(y);
      }
      itery->second.push_back(newpt);
    }
    int max_side = 0;
    for (auto &pairx : ptx)
    {
      // If a column has fewer than sqrt(size) points, try all pairs of its points
      // as the left edge of the square. Otherwise try all the pairs (pt1, pt2),
      // where pt1 is from the column and pt2 is in the same row as pt1, as the top edge
      // of the square.
      bool col_pairs = (pairx.second.size() > size / pairx.second.size());
      for (Point &pt1 : pairx.second)
      {
        if(col_pairs)
        {
          const auto &itery = pty.find(pt1.y);
          for(Point &pt2 : itery->second)
          {
            if(pt2.x - pt1.x <= max_side)
              continue;
            if(test_pair(pt1, pt2, ptset))
              max_side = pt2.x - pt1.x;
          }
        }
        else
        {
          for(Point &pt2 : pairx.second)
          {
            if(pt2.y - pt1.y <= max_side)
              continue;
            if(test_pair(pt1, pt2, ptset))
              max_side = pt2.y - pt1.y;
          }
        }
      }
    }
    cout << max_side << endl;
  }
  return 0;
}
