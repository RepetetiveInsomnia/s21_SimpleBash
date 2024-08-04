#!/bin/bash

YES=0
NO=0
COUNTER=0
DIFF_RES=""

my_grep=(
"./s21_grep"
)
my_result=(
"my_result.txt"
)
grepp=(
    "grep"
)
grep_result=(
    "grep_result.txt"
)
for var in v c l n h o
do
for path in testing_grep.txt no_test.txt
do
for patt in evil blood
do
$my_grep -$var -e$patt $path > my_result.txt
$grepp -$var  -e$patt $path > grep_result.txt
DIFF_RES="$(diff -s my_result.txt grep_result.txt)"
(( COUNTER++ ))
if [ "$DIFF_RES" == "Files my_result.txt and grep_result.txt are identical" ]
    then
      (( YES++ ))
        echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[32msuccess\033[0m/Path is:$path options are:-$var"
    else
      (( NO++ ))
        echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[31mfail\033[0m/Path is:$path options are:-$var"
    fi
done
done
done

for var in v c l n h
do
for path in testing_grep.txt no_test.txt
do
for patt in evil.txt blood.txt
do
$my_grep -$var -f$patt $path > my_result.txt
$grepp -$var  -f$patt $path > grep_result.txt
DIFF_RES="$(diff -s my_result.txt grep_result.txt)"
(( COUNTER++ ))
if [ "$DIFF_RES" == "Files my_result.txt and grep_result.txt are identical" ]
    then
      (( YES++ ))
        echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[32msuccess\033[0m/Path is:$path options are:-$var"
    else
      (( NO++ ))
        echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[31mfail\033[0m/Path is:$path options are:-$var"
    fi
done
done
done

for var in v c l n h
do
for path in testing_grep.txt no_test.txt
do
$my_grep -$var -eevil -e blood $path > my_result.txt
$grepp -$var  -eevil -e blood $path > grep_result.txt
DIFF_RES="$(diff -s my_result.txt grep_result.txt)"
(( COUNTER++ ))
if [ "$DIFF_RES" == "Files my_result.txt and grep_result.txt are identical" ]
    then
      (( YES++ ))
        echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[32msuccess\033[0m/Path is:$path options are:-$var"
    else
      (( NO++ ))
        echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[31mfail\033[0m/Path is:$path options are:-$var"
    fi
done
done


for var in v c l n h
do
for path in testing_grep.txt no_test.txt
do
$my_grep -$var evil $path > my_result.txt
$grepp -$var  evil $path > grep_result.txt
DIFF_RES="$(diff -s my_result.txt grep_result.txt)"
(( COUNTER++ ))
if [ "$DIFF_RES" == "Files my_result.txt and grep_result.txt are identical" ]
    then
      (( YES++ ))
        echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[32msuccess\033[0m/Path is:$path options are:-$var"
    else
      (( NO++ ))
        echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[31mfail\033[0m/Path is:$path options are:-$var"
    fi
done
done

for var in v c l n h
do
for path in testing_grep.txt no_test.txt
do
$my_grep -$var -fevil.txt -f blood.txt $path > my_result.txt
$grepp -$var  -fevil.txt -f blood.txt $path > grep_result.txt
DIFF_RES="$(diff -s my_result.txt grep_result.txt)"
(( COUNTER++ ))
if [ "$DIFF_RES" == "Files my_result.txt and grep_result.txt are identical" ]
    then
      (( YES++ ))
        echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[32msuccess\033[0m/Path is:$path options are:-$var"
    else
      (( NO++ ))
        echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[31mfail\033[0m/Path is:$path options are:-$var"
    fi
done
done

for var1 in v c l n h o
do
    for var2 in v c l n h o
    do
        if [ $var1 != $var2 ]
        then
        for path in testing_grep.txt no_test.txt
        do
                var="$var1 -$var2"
                $my_grep -$var evil $path > my_result.txt
                $grepp -$var evil $path > grep_result.txt
                DIFF_RES="$(diff -s my_result.txt grep_result.txt)"
                (( COUNTER++ ))
                if [ "$DIFF_RES" == "Files my_result.txt and grep_result.txt are identical" ]
                    then
                    (( YES++ ))
                        echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[32msuccess\033[0m/Path is:$path options are:-$var"
                    else
                    (( NO++ ))
                        echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[31mfail\033[0m/Path is:$path options are:-$var"
                    fi
                var="$var1$var2"
                $my_grep -$var evil $path > my_result.txt
                $grepp -$var evil $path > grep_result.txt
                DIFF_RES="$(diff -s my_result.txt grep_result.txt)"
                (( COUNTER++ ))
                if [ "$DIFF_RES" == "Files my_result.txt and grep_result.txt are identical" ]
                    then
                    (( YES++ ))
                        echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[32msuccess\033[0m/Path is:$path options are:-$var"
                    else
                    (( NO++ ))
                        echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[31mfail\033[0m/Path is:$path options are:-$var"
                    fi
                done

        fi
    done
done

for var1 in v c l n h o
do
    for var2 in v c l n h o
    do
        for var3 in v c l n h o
        do
            if [ $var1 != $var2 ] && [ $var2 != $var3 ] && [ $var1 != $var3 ]
            then
            for path in testing_grep.txt no_test.txt
            do
                var="$var1 -$var2 -$var3"
                $my_grep -$var evil $path > my_result.txt
                $grepp -$var evil $path > grep_result.txt
                DIFF_RES="$(diff -s my_result.txt grep_result.txt)"
                (( COUNTER++ ))
                if [ "$DIFF_RES" == "Files my_result.txt and grep_result.txt are identical" ]
                    then
                    (( YES++ ))
                        echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[32msuccess\033[0m/Path is:$path options are:-$var"
                    else
                    (( NO++ ))
                        echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[31mfail\033[0m/Path is:$path options are:-$var"
                    fi
                var="$var1$var2var3"
                $my_grep -$var evil $path > my_result.txt
                $grepp -$var evil $path > grep_result.txt
                DIFF_RES="$(diff -s my_result.txt grep_result.txt)"
                (( COUNTER++ ))
                if [ "$DIFF_RES" == "Files my_result.txt and grep_result.txt are identical" ]
                    then
                    (( YES++ ))
                        echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[32msuccess\033[0m/Path is:$path options are:-$var"
                    else
                    (( NO++ ))
                        echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[31mfail\033[0m/Path is:$path options are:-$var"
                    fi
                done
            fi
        done
            
    done
done

rm my_result.txt grep_result.txt

echo "FAILS: $NO"
echo "SUCCESSFUL: $YES"
echo "ALL: $COUNTER"
