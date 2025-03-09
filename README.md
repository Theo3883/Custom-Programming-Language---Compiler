# Limbaj Programming Language

## Features

- **Custom Language Parsing**: Implements a custom programming language with its own syntax and semantics.

- **Lexical Analysis**: Uses Flex to perform lexical analysis, converting input text into tokens.

- **Syntax Analysis**: Utilizes Bison for syntax analysis, constructing a parse tree from tokens.

- **Symbol Table Management**: Manages symbol tables to keep track of variable and function declarations and their scopes.

- **Type Checking**: Performs type checking to ensure that operations are performed on compatible types.

- **Error Reporting**: Provides detailed error messages for syntax and semantic errors, including type mismatches.

- **Code Generation**: Generates intermediate code for the custom language, which can be further processed or executed.

- **Function and Class Support**: Supports the definition and usage of functions and classes, including member functions and variables.

- **Control Structures**: Implements control structures such as if-else, while, and for loops.

- **Code Architecture and Reusability**: Emphasizes modular code architecture and reusability.

- **Predefined Data Types**: Supports predefined data types such as Bool, Char, Integer, Float, and String.

- **Array Types**: Supports array types and accessing array elements at specific indices.

- **Expressions**: Allows complex expressions and string operations.

- **Variable/Function Redeclaration**: Prevents variables and functions from being redeclared.

- **Const Variables**: Supports const variables that cannot be changed after declaration.

- **Function Call Signature**: Ensures that function call signatures must match the function definition.

- **Print Expression**: Provides a `print` function to output expressions.

- **Eval Function**: Includes an `Eval(exp)` function that evaluates an Integer expression.

## Technologies Used

- **C++**
- **Flex**
- **Bison**