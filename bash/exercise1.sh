####################################################################################################################
#    _,.----.     ,---.                  _,.----.                            _,.---._     .-._         
#  .' .' -   \  .--.'  \       _.-.    .' .' -   \  .--.-. .-.-.   _.-.    ,-.' , -  `.  /==/ \  .-._  
# /==/  ,  ,-'  \==\-/\ \    .-,.'|   /==/  ,  ,-' /==/ -|/=/  | .-,.'|   /==/_,  ,  - \ |==|, \/ /, / 
# |==|-   |  .  /==/-|_\ |  |==|, |   |==|-   |  . |==| ,||=| -||==|, |  |==|   .=.     ||==|-  \|  |  
# |==|_   `-' \ \==\,   - \ |==|- |   |==|_   `-' \|==|- | =/  ||==|- |  |==|_ : ;=:  - ||==| ,  | -|  
# |==|   _  , | /==/ -   ,| |==|, |   |==|   _  , ||==|,  \/ - ||==|, |  |==| , '='     ||==| -   _ |  
# \==\.       //==/-  /\ - \|==|- `-._\==\.       /|==|-   ,   /|==|- `-._\==\ -    ,_ / |==|  /\ , |  
#  `-.`.___.-' \==\ _.\=\.-'/==/ - , ,/`-.`.___.-' /==/ , _  .' /==/ - , ,/'.='. -   .'  /==/, | |- |  
#               `--`        `--`-----'             `--`..---'   `--`-----'   `--`--''    `--`./  `--` 
# 
# Create a bash script which accepts as input a string representing an arithmetic operation composed by the following
# operations and paretheses: +,-,*,^, /, (, ).
# 
# The script must return the result of such operation rounded to 4 decimal digits.
#
# Some example inputs are:
#  - 5+50*3/20 + (17*2)/7
#  - (91.5*7+50*3)/20 + (17^2)/7
#  - 91+50*3/20 + (17^2)/7
# 
####################################################################################################################
# !/bin/bash
# Run this script with bash ./exercise1.sh <filename>.txt where file is in the same directory as the script
# file contains the expression to be evaluated in each line. An example file called calc.txt is also provided for testing
while read in; do a=`echo "$in" | bc -l`; printf "%.4f\n" $a; done < $1