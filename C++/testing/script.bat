@echo off


echo.

:: Check if the user provided the number of test cases
if "%1"=="" (
    echo Error: Please provide the number of test cases as an argument.
    echo Usage: script.bat T
    echo Where T is the total number of test cases.
    exit /b
)

:: Get the number of test cases from the first argument
set TOTAL_TESTS=%1

:: Compile programs

echo Compiling generator.cpp...
g++ generator.cpp -o generator || (
    echo Compilation failed for generator.cpp
    exit /b
)

echo Compiling bruteforce.cpp...
g++ bruteforce.cpp -o bruteforce || (
    echo Compilation failed for bruteforce.cpp
    exit /b
)

echo Compiling sourcecode.cpp...
g++ sourcecode.cpp -o sourcecode || (
    echo Compilation failed for sourcecode.cpp
    exit /b
)

echo.
echo.

:: Run tests
echo Starting Stress-Testing with %TOTAL_TESTS% Test-Cases: -
echo.

for /L %%i in (1,1,%TOTAL_TESTS%) do (

    echo Running Test #%%i...

    :: Generate test case
    generator.exe > TestCase.txt

    :: Run brute-force solution
    bruteforce.exe < TestCase.txt > BruteOutput.txt

    :: Run optimized solution
    sourcecode.exe < TestCase.txt > SourceOutput.txt

    :: Compare outputs
    fc BruteOutput.txt SourceOutput.txt > nul
    if errorlevel 1 (

        echo Test #%%i Failed!
	echo.
        echo Input: -
        echo.
        type TestCase.txt
        echo.

        echo Bruteforce Output: -
	echo.
        type BruteOutput.txt
        echo.

        echo Sourcecode Output: -
        echo.
        type SourceOutput.txt
        echo.
        echo Debug and fix the issue before retrying...
	echo.
        exit /b
    ) else (
	echo.
        echo Test #%%i Passed!
	echo.
    )
)

echo All tests passed successfully!
echo.
pause
