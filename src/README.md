In CMake, usually an executable or a library is referred to as a 'target'.
Roughly, my basic CMake design flow usually looks like this:
1.    build libraries using `add_library`;
2.    specify the directories to be included in the target libraries by `target_include_directories`;
3.    create an executable for the project using `add_executable`;
4.    (optional) use `target_include_directories` for the target executable; it is optional
  if the libraries to be linked later to the exectuable had used the `PUBLIC` propagation policy
  in their `target_include_directories` invocation;
5.    link the built libraries to the exectuable using `target_link_libraries`.
