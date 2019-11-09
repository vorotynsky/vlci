# Vorotynsky's lambda calculus interpreter

VLCI is a small software to calculate lambda expressions.

*aim*: create a program to run untyped lambdas.

## Components

 - `vlcp`. Lambda calculus processor is a library what parses lambda expressions and execute theirs.
 - `client` is console ui.
 - `tests` is unit testing for `vlcp`
 - `docs` documentation.

## BUILD

1. Install cmake.

1. To build vlci use following commands:

```
cmake .
cmake --build .
```

### Testing

By default testing added to cmake file. `ENABLE_TESTING` is a parameter to enable/disable testing.

> Testing requires `Catch2`.

```bash
cmake --DENABLE_TESTING=OFF . # turn off testing OR
cmake --DENABLE_TESTING=ON  . # turn on testing

cmake --build .
ctest .
```

### Documentation

To enable/disable documentation generating toggle `GENERATE_DOCS`. Documentation generates if Doxygen installed.

> Documentation building requires `Doxygen` and `moxygen`.

```bash
cmake --DGENERATE_DOCS=ON  .

cmake --build .
ctest .
```
