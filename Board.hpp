#include <string>
#include "Direction.hpp"

namespace ariel {
    class Board {
        char* chars;
        uint rows;
        uint colums;
    public:
        Board() {}
        ~Board() { }
        void post(int row, int column, Direction direction,std::string message);
        static std::string read(int row, int column, Direction direction, int length);
        void show();
    };
}
