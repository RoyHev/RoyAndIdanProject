cmake_minimum_required(VERSION 3.13)
project(Ex3)

set(CMAKE_CXX_STANDARD 14)

add_executable(Ex3 main.cpp Lexer.cpp Lexer.h Expression.h BinaryExpression.cpp BinaryExpression.h Minus.cpp Minus.h Plus.cpp Plus.h Divide.cpp Divide.h Multiply.cpp Multiply.h UnaryExpression.cpp UnaryExpression.h Negative.cpp Negative.h Number.cpp Number.h Expression.cpp Parser.cpp Parser.h Command.h CommandExpression.h CommandExpression.cpp ShuntingYard.cpp ShuntingYard.h Var.cpp Var.h OpenDataServerCommand.cpp OpenDataServerCommand.h IfCommand.cpp IfCommand.h ConditionParser.h LoopCommand.cpp LoopCommand.h ConnectCommand.cpp ConnectCommand.h CreateVarCommand.cpp CreateVarCommand.h AssignCommand.cpp AssignCommand.h PrintCommand.cpp PrintCommand.h SleepCommand.cpp SleepCommand.h BindCommand.cpp BindCommand.h VarManager.cpp VarManager.h ConditionParser.cpp)