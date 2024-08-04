#!/bin/bash

YES=0
NO=0
COUNTER=0
DIFF_RES=""

my_cat=(
"./s21_cat"
)
my_result=(
"my_result.txt"
)
catt=(
    "cat"
)
cat_result=(
    "cat_result.txt"
)
for var1 in b e n s t v
do
for path in testing_cat.txt no_test.txt
do
$my_cat -$var1 $path > my_result.txt
$catt -$var1 $path > cat_result.txt
DIFF_RES="$(diff -s my_result.txt cat_result.txt)"
(( COUNTER++ ))
if [ "$DIFF_RES" == "Files my_result.txt and cat_result.txt are identical" ]
    then
      (( YES++ ))
        echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[32msuccess\033[0m/Path is:$path options are:$var"
    else
      (( NO++ ))
        echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[31mfail\033[0m/Path is:$path options are:$var"
    fi
done
done

for var1 in b e n s t v
do
    for var2 in b e n s t v
    do
        if [ $var1 != $var2 ]
        then
        for path in testing_cat.txt no_test.txt
        do
                var="$var1 -$var2"
                $my_cat -$var $path > my_result.txt
                $catt -$var $path > cat_result.txt
                DIFF_RES="$(diff -s my_result.txt cat_result.txt)"
                (( COUNTER++ ))
                if [ "$DIFF_RES" == "Files my_result.txt and cat_result.txt are identical" ]
                then
                (( YES++ ))
                    echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[32msuccess\033[0m/Path is:$path options are:$var"
                else
                (( NO++ ))
                    echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[31mfail\033[0m/Path is:$path options are:$var"
                fi
                var="$var1$var2"
                $my_cat -$var $path > my_result.txt
                $catt -$var $path > cat_result.txt
                DIFF_RES="$(diff -s my_result.txt cat_result.txt)"
                (( COUNTER++ ))
                if [ "$DIFF_RES" == "Files my_result.txt and cat_result.txt are identical" ]
                then
                (( YES++ ))
                    echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[32msuccess\033[0m/Path is:$path options are:$var"
                else
                (( NO++ ))
                    echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[31mfail\033[0m/Path is:$path options are:$var"
                fi
                done

        fi
    done
done

for var1 in b e n s t v
do
    for var2 in b e n s t v
    do
        for var3 in b e n s t v
        do
            if [ $var1 != $var2 ] && [ $var2 != $var3 ] && [ $var1 != $var3 ]
            then
            for path in testing_cat.txt no_test.txt
            do
                var="$var1 -$var2 -$var3"
                $my_cat -$var $path > my_result.txt
                $catt -$var $path > cat_result.txt
                DIFF_RES="$(diff -s my_result.txt cat_result.txt)"
                (( COUNTER++ ))
                if [ "$DIFF_RES" == "Files my_result.txt and cat_result.txt are identical" ]
                then
                (( YES++ ))
                    echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[32msuccess\033[0m/Path is:$path options are:$var"
                else
                (( NO++ ))
                    echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[31mfail\033[0m/Path is:$path options are:$var"
                fi
                var="$var1$var2var3"
                $my_cat -$var $path > my_result.txt
                $catt -$var $path > cat_result.txt
                DIFF_RES="$(diff -s my_result.txt cat_result.txt)"
                (( COUNTER++ ))
                if [ "$DIFF_RES" == "Files my_result.txt and cat_result.txt are identical" ]
                then
                (( YES++ ))
                    echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[32msuccess\033[0m/Path is:$path options are:$var"
                else
                (( NO++ ))
                    echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[31mfail\033[0m/Path is:$path options are:$var"
                fi
                done
            fi
        done
            
    done
done

for var1 in b e n s t v
do
    for var2 in b e n s t v
    do
        for var3 in b e n s t v
        do
            for var4 in b e n s t v
            do
                if [ $var1 != $var2 ] && [ $var2 != $var3 ] \
                && [ $var1 != $var3 ] && [ $var1 != $var4 ] \
                && [ $var2 != $var4 ] && [ $var3 != $var4 ]
                then
                for path in testing_cat.txt no_test.txt
                do
                var="$var1 -$var2 -$var3 -$var4"
                $my_cat -$var $path > my_result.txt
                $catt -$var $path > cat_result.txt
                DIFF_RES="$(diff -s my_result.txt cat_result.txt)"
                (( COUNTER++ ))
                if [ "$DIFF_RES" == "Files my_result.txt and cat_result.txt are identical" ]
                then
                (( YES++ ))
                    echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[32msuccess\033[0m/Path is:$path options are:$var"
                else
                (( NO++ ))
                    echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[31mfail\033[0m/Path is:$path options are:$var"
                fi
                var="$var1$var2var3var4"
                $my_cat -$var $path > my_result.txt
                $catt -$var $path > cat_result.txt
                DIFF_RES="$(diff -s my_result.txt cat_result.txt)"
                (( COUNTER++ ))
                if [ "$DIFF_RES" == "Files my_result.txt and cat_result.txt are identical" ]
                then
                (( YES++ ))
                    echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[32msuccess\033[0m/Path is:$path options are:$var"
                else
                (( NO++ ))
                    echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[31mfail\033[0m/Path is:$path options are:$var"
                fi
                done
                fi
            done
        done
    done
done

rm my_result.txt cat_result.txt

echo "FAILS: $NO"
echo "SUCCESSFUL: $YES"
echo "ALL: $COUNTER"
