#include "args.hpp"

#include <iostream>

boost::program_options::variables_map parse_command_line_options(int argc, char* argv[])
{
    boost::program_options::options_description desc("Allowed options");
    desc.add_options()
        ("help", "produce help message")
        ("file", boost::program_options::value<std::string>(), "OTF2 file to open")
    ;

    boost::program_options::variables_map vm;
    boost::program_options::store(
        boost::program_options::parse_command_line(argc, argv, desc), vm
    );
    boost::program_options::notify(vm);    

    if (vm.count("help"))
    {
        std::cout << desc << std::endl;
        vm.clear();
    }

    return vm;
}