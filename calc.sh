code=$(cloc --hide-rate --quiet --sum-one -csv --list-file source_code_file_list | awk 'END{print}' | awk -F "," '{print $NF}')

spec_in_code=$(cat source_code_file_list | xargs python3 count.py)

spec_cloc_output=$(cloc --hide-rate --quiet --sum-one -csv specs/spec.c | awk 'END{print}')
lemmas_cloc_output=$(cloc --hide-rate --quiet --sum-one -csv lemmas.c | awk 'END{print}')

spec_code=$(echo $spec_cloc_output | awk -F "," '{print $NF}')
spec_comments=$(echo $spec_cloc_output | awk -F "," '{print $(NF-1)}')

lemmas_code=$(echo $lemmas_cloc_output | awk -F "," '{print $NF}')
lemmas_comments=$(echo $lemmas_cloc_output | awk -F "," '{print $(NF-1)}')

lemma_stmnts=$(($lemmas_code + $lemmas_comments))
specs=$(($spec_code + $spec_comments + $spec_in_code))
formalization=$(($specs + $lemma_stmnts))

overhead=$( echo "$formalization / $code" | bc -l )


echo "Code: $code"
echo "Spec: $specs"
echo "Lemma stmts: $lemma_stmnts"
echo "Formalisation total: $formalization"
echo "Overhead total: $overhead"
