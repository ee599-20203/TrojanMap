#include <map>
#include <vector>

#include "gtest/gtest.h"
#include "src/lib/trojanmap.h"

//Test GetLat function
TEST(TrojanMapStudentTest, GetLat) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();//data complete
  
  std::string id = "33078887";
  double real = m.GetLat(id);
  double expected = 34.026738;
  EXPECT_EQ(expected, real);
}

//Test GetLon function
TEST(TrojanMapStudentTest, GetLon) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();//data complete

  std::string id = "63765376";
  double real = m.GetLon(id);
  double expected = -118.2817732;
  EXPECT_EQ(expected, real);
}

//Test GetName function
TEST(TrojanMapStudentTest, GetName) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();//data complete

  std::string id = "614990288";
  std::string real = m.GetName(id);
  std::string expected = "Trojan Grounds Starbucks";
  EXPECT_EQ(expected, real);
}

//Test GetNode function 
TEST(TrojanMapStudentTest, GetNode) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();//data complete

  std::string name = "Parking Center";
  Node real = m.GetNode(name);//Node exp("732642214",34.0199998,-118.277186,"Parking Center",{"4012759746"});

  auto expid = "732642214";
  double explat = 34.0199998;
  double explon = -118.277186;
  auto expname = "Parking Center";
  std::vector<std::string> expneighbors = {"4012759746"};

  EXPECT_EQ(expid, real.id);
  EXPECT_EQ(explat, real.lat);
  EXPECT_EQ(explon, real.lon);
  EXPECT_EQ(expname, real.name);
  EXPECT_EQ(expneighbors,real.neighbors);  
}

//Test GetNeighborIDs function
TEST(TrojanMapStudentTest, GetNeighborIDs) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();//data complete
  
  auto id = "932378219";
  std::vector<std::string> real = m.GetNeighborIDs(id);
  std::vector<std::string>  expected = {"6226313827", "6814990112", "6226313826"};
  EXPECT_EQ(expected, real);
}

//Test CalculateDistance function
TEST(TrojanMapStudentTest, CalculateDistance) {
  TrojanMap m;
  //m.CreateGraphFromCSVFile();//data complete
  
  Node a;//20400292	34.0273404	-118.2765547
  a.lat = 34.0273404;
  a.lon = -118.2765547;

  Node b;//21098539	34.02549	-118.2915534
  b.lat = 34.02549;
  b.lon = -118.2915534;

  // Node a;//21098539	34.02549	-118.2915534
  // a.lat = 34.02549;
  // a.lon = -118.2915534;

  // Node b;//21098546	34.030993	-118.2647022
  // b.lat = 34.030993;
  // b.lon = -118.2647022;

  double c = m.CalculateDistance(a,b);
  double real = (double)(int)(c * 100000.0)/100000.0; 
  double exp = 0.86882;
  EXPECT_EQ(exp, real);
}


//Test CalculatePathLength function
TEST(TrojanMapStudentTest, CalculatePathLength) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();//data complete

  std::vector<std::string> path = {"20400292","21098539","21098546"};
  double c = m.CalculatePathLength(path);
  double real = (double)(int)(c * 100000.0)/100000.0; 
  double exp = 2.45359;//0.86882+1.58476
  EXPECT_EQ(exp, real);
}

//Test Autocomplete function
TEST(TrojanMapTest, Autocomplete) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();//data complete
  std::vector<std::string> exp_names = {"USC Fisher Museum of Art", "USC Village Gym","USC Parking","USC Village Dining Hall"}; 
  
  // Test the simple case
  auto real_names = m.Autocomplete("USC");
  EXPECT_EQ(real_names, exp_names);
  
  // Test the lower case
  real_names = m.Autocomplete("usc");
  EXPECT_EQ(real_names, exp_names);
 
  // Test the lower and upper case 
  real_names = m.Autocomplete("Usc"); 
  EXPECT_EQ(real_names, exp_names);
}


//Test GetPosition function
TEST(TrojanMapTest, GetPosition) {
  TrojanMap m;
  m.CreateGraphFromCSVFile();//data complete

  auto name1 = "Massman Theatre";
  std::pair<double, double> real_pair1 =  m.GetPosition(name1);
  std::pair<double, double> exp_pair1(34.0226664,-118.2899311);
  EXPECT_EQ(real_pair1, exp_pair1);

  auto name2 = "Crosswalk1";
  std::pair<double, double> real_pair2 =  m.GetPosition(name2);
  std::pair<double, double> exp_pair2(34.0302951,-118.2857237);
  EXPECT_EQ(real_pair2, exp_pair2); 
}

//Test CalculateShortestPath_Dijkstra function
//Test CalculateShortestPath_Bellman_Ford function
//Test ReadLocationsFromCSVFile function
//Test ReadDependenciesFromCSVFile function
//Test ReadDependenciesFromCSVFile function
//Test TravellingTrojan function
//Test TravellingTrojan_2opt function
//Test IsCyclicUttil funciton
//Test CycleDetection function
