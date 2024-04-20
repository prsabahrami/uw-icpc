#include "testlib.h"
#include <sstream>
#include <vector>
#include <string>

int main(int argc, char* argv[]) {
    // This command initializes checker environment.
    registerTestlibCmd(argc, argv);
    // Now there are three global variables specifying testlib streams:
    // inf - stream with the testdata.
    // ouf - stream with the contestant output.
    // ans - stream with the jury answer.
    // All those streams provide the similar interface for reading data.

    // This function reads a single integer from the participant output that 
    // should be between -2000 and 2000. If it doesn't belong to the specified
    // range, checker finishes with verdict _pe and comment saying that [sum of numbers]
    // is outside of the specified range.
    //int pans = ouf.readInt(-2000, 2000, "sum of numbers");
    
    // This function reads a single integer from the jury output. Here we suppose
    // that jury's answer is correct and we do not need to additionally verify it.
    //int jans = ans.readInt(); // We suppose that jury's answer is correct
    
    int pans = ouf.readInt();
    int jans = ans.readInt();

    if (pans != jans)
        quitf(_wa, "The maximum sum is wrong: expected = %d, found = %d", jans, pans);

    int courses = inf.readInt();
    int students = inf.readInt();
    int happy = 0;

    std::vector<int> cap;
    std::vector<int> enr;
    for(int i = 0; i < courses; i++) {
      int c = inf.readInt();
      cap.push_back(c);
      enr.push_back(0);
    }

    inf.readLine();
    ouf.readLine();

    for(int i = 0; i < students; i++) {
      std::string choicesStr = inf.readLine();
      std::string gotStr = ouf.readLine();
      //std::cout << "Choices: " << choicesStr << std::endl;
      //std::cout << "Got: " << gotStr << std::endl;
      std::stringstream ss(choicesStr);
      int number;
      std::vector<int> choices;
      while ( ss >> number )
        choices.push_back( number );
      std::stringstream ss2(gotStr);
      std::vector<int> seen;
      while ( ss2 >> number ) {
        if(std::count(seen.begin(), seen.end(), number))
          quitf(_wa, "repeated course %s", gotStr.c_str());
        seen.push_back(number);
        if(std::count(choices.begin(), choices.end(), number) == 0) {
          quitf(_wa, "Student %d enrolled in course %d but selected %s", i+1, number, choicesStr.c_str());
        }
        enr[number-1]++;
        if(enr[number-1] > cap[number-1]) {
          quitf(_wa, "Course %d has more than %d students", number, cap[number-1]);
        }
        happy++;
      }
    }

    if(happy != pans)
        quitf(_wa, "The sum doesnt add up: expected = %d, actual happiness = %d", pans, happy);

    quitf(_ok, "All good.."); // This finishes checker with verdit OK.
}
