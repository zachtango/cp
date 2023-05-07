/*
BEGIN ANNOTATION
PROBLEM URL: https://open.kattis.com/problems/officespace
TAGS: brute-force
EXPLANATION:
    Given w and h (1 to 100)

    n employees
    name x1 y1 x2 y2

    return
        unallocated (number of square feet no employee wants)
        contested (number of square feet more than one employee wants access)
        employee allocated (number of square feet employee is guaranteed [no other employees want])
    
    we can brute force this problem by representing the office space in a 2d grid, and filling in the grid with each employee's requested space

    for each test case:
    key map:
        -1 means unallocated
        -2 means contested
        i means the index of the single employee in std::string[] employee_list this space is allocated to

    1. start with a 101 by 101 2d array, office_space
    2. for all pairs (a, b) where a in [0, w - 1] and b in [0, h - 1] 
    3. for each employee i
        1. get x1 y1 and x2 y2
        2. for all pairs (a, b) where a in [x1, x2 - 1] and b in [y1, y2 - 1]
            1. if office_space[a][b] == -1 (unallocated)
                then we can allocate the office_space to the employee by setting office_space[a][b] = i
                else this space is already allocated, so we set the office_space[a][b] = -2
    4. keep a counter for unallocated, contested, and employee_allocated[n] to count these metrics
    5. for all pairs (a, b) where a in [0, w - 1] and b in [0, h - 1] 
        1. if office_space[a][b] == -1, unallocated += 1
        2. else if office_space[a][b] == -2, contested += 1
        3. else, space is allocated, employee_allocated[office_space[a][b]] += 1
    6. print out these metrics

    one test case will run in O(n * w * h)
    there are t tests cases so the total run time is O(t * n * w * h)
        because t <= 10 and n <= 20 and w <= 100 and h <= 100 are small bounds,
        this is doable in the time available (3 seconds)
*/

#include <string>
#include <iostream>

int main() {
    int office_space[101][101];
    
    std::string employee_names[20];
    
    int w, h;
    while(std::cin >> w, std::cin >> h) {
        int n;
        std::cin >> n;

        // 2. set all space within 0, 0 and w, h to unallocated
        for(int i = 0; i < w; i++) {
            for(int j = 0; j < h; j++) {
                office_space[i][j] = -1;
            }
        }

        // 3. for each employee, fill their space in office_space
        std::string employee_name;

        for(int e = 0; e < n; e++) {
            std::cin >> employee_name;

            employee_names[e] = employee_name;

            int x1, y1, x2, y2;
            std::cin >> x1 >> y1 >> x2 >> y2;

            for(int i = x1; i < x2; i++) {
                for(int j = y1; j < y2; j++) {
                    if(office_space[i][j] == -1) {
                        // allocate employee
                        office_space[i][j] = e;
                    } else {
                        // mark space as contested
                        office_space[i][j] = -2;
                    }
                }
            }
        }

        // 4. keep a counter for unallocated, contested, and employee_allocated[n]
        int unallocated = 0,
            contested = 0,
            employee_allocated[n];

        for(int i = 0; i < n; i++)
            employee_allocated[i] = 0;
        
        // 5. count unnallocated, contested, and employee_allocated[n]
        for(int i = 0; i < w; i++) {
            for(int j = 0; j < h; j++) {
                switch(office_space[i][j]) {
                    // unallocated
                    case -1:
                        unallocated += 1;
                        break;

                    // contested
                    case -2:
                        contested += 1;
                        break;

                    // employee allocated
                    default:
                        employee_allocated[office_space[i][j]] += 1;
                }
            }
        }
        
        // 6. print out metrics
        std::cout << "Total " << (w * h) << '\n'
                    << "Unallocated " << unallocated << '\n'
                    << "Contested " << contested << '\n';

        for(int i = 0; i < n; i++) {
            std::cout << employee_names[i] << ' ' << employee_allocated[i] << '\n';
        }
        
        std::cout << '\n';
    }
}
