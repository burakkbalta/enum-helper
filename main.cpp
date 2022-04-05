#include "MacroEnum.h"
#include "CustomEnum.h"

MACRO_ENUM(LOGTYPES, Debug, Error, Fatal, Warning)
MACRO_ENUM_WITH_VALUE(LOGTYPESWITHVALUES, int, Debug=3, Error=4, Fatal=5, Warning=6)

static constexpr CustomEnum DEBUG{10, "DEBUG"};
static constexpr CustomEnum ERROR{11, "ERROR"};
static constexpr CustomEnum FATAL{12, "FATAL"};
static constexpr CustomEnum WARNING{13, "WARNING"};

int main()
{
    std::cout << "---- Print LOGTYPES -----" << "\n";
    std::cout << EnumToString(LOGTYPES::Error) << std::endl;
    PrintAll_LOGTYPES_Enum();
    std::cout << "---- Print LOGTYPES End ----" << "\n";

    std::cout << "---- Print LOGTYPESWITHVALUES -----" << "\n";
    std::cout << EnumToString(LOGTYPESWITHVALUES::Debug) << std::endl;
    PrintAll_LOGTYPESWITHVALUES_Enum();
    std::cout << "---- Print LOGTYPESWITHVALUES End ----" << "\n";

    std::cout << "---- Print CustomEnum -------" << "\n";
    std::cout << DEBUG.GetValue() << " : " << DEBUG.GetName() << "\n";
    std::cout << ERROR.GetValue() << " : " << ERROR.GetName() << "\n";
    std::cout << FATAL.GetValue() << " : " << FATAL.GetName() << "\n";
    std::cout << WARNING.GetValue() << " : " << WARNING.GetName() << "\n";
    std::cout << "---- Print CustomEnum End -------" << "\n";
    return 0;
}