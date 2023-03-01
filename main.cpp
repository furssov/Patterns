
#include <SFML/Graphics.hpp>

#include "AppCore.h"

using namespace sf;
int main()
{


    AppCore *a = AppCore::get_instance(1000, 1000);
    a->start();



    return 0;
}
