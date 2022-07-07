cmake_minimum_required(VERSION 3.22)
project(CompilationPrograms C)

set(CMAKE_C_STANDARD 99)

add_executable(Activity1_Midterms Activities/Midterms/Activity1.c)
add_executable(Actvity2_Midterms Activities/Midterms/Activity2.c)
add_executable(Assignment1_Midterms Activities/Midterms/Assignment1.c)

add_executable(Quiz1_Midterm Quizzes/Midterms/Quiz1.c)

add_executable(MidtermExam Exams/MidtermExam.c)
