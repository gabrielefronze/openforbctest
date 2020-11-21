####################################################################################################################
#       __  ___      ___  _______   _______        __       _______    _______   _______   
#      /""\|"  \    /"  |/"     "| /"      \      /""\     /" _   "|  /"     "| /"      \  
#     /    \\   \  //  /(: ______)|:        |    /    \   (: ( \___) (: ______)|:        | 
#    /' /\  \\\  \/. ./  \/    |  |_____/   )   /' /\  \   \/ \       \/    |  |_____/   ) 
#   //  __'  \\.    //   // ___)_  //      /   //  __'  \  //  \ ___  // ___)_  //      /  
#  /   /  \\  \\\   /   (:      "||:  __   \  /   /  \\  \(:   _(  _|(:      "||:  __   \  
# (___/    \___)\__/     \_______)|__|  \___)(___/    \___)\_______)  \_______)|__|  \___) 
#                                                                                          
# Create a shell script able to inject a file with one number per line and return their average.
# It must support an arbitrary file length.
#
# Bonus: in case the lines are CSV (comma-separed values) treat each column as a different file, returning the 
#        averages as a single CSV line.
# 
####################################################################################################################
# !/bin/bash
# Run this script with bash ./exercise2.sh <filename>.txt/csv where file is in the same directory as the script
# Side note: You might have to dos2unix this file to change line endings in case of unexpected errors, since I am coding on Windows (guilty!)
# Side note 2: I have also provided test files with my submissions, namely numbers.txt and numbers.csv
filename=$1
echo "$filename"
ext=${filename#*.}
if [ "$ext" == "txt" ] 
then
    awk '{ total += $1; count++ } END { print total/count }' $1;
else
    awk -F ';' '{ for(i=1;i<=NF;i++) total[i]+=$i ; } END { for(i=1;i<=NF;i++) printf "%f ",total[i]/NR ;}' $1 > output.csv;
fi
# awk -F ';' '{print;x+=$2}END{print "MEAN" x/NR}' $1 > output.csv;
# awk '{ total += $1; count++ } END { print total/count }' $1;