#sleep 30


executable=("BBI")

length=(850000)
ops=(0 10000 50000 100000 150000)

outfile=resultsEnergy$(date +"%Y-%m-%d-%H:%M:%S").data

cols=("ExpNumber" "NumElements" "NumOps"
      "TimeSec" "EnergyCores" "EnergyPkg" "EnergyRAM" "Instructions" "LLCLoads"
      "LLCLoadMisses" "LLCStores" "LLCStoresMisses" "L1DcacheLoads"
      "L1DcacheLoadMisses" "L1DcacheStores" "CacheMisses"
      "CacheReferences" "Branches" "Branch-Misses" "CpuCycles")

numcols=$(echo ${cols[@]})
columns=$(echo ${numcols// /;})
echo $columns >> ${outfile}

numalgos=${#executable[@]} # @ todos los elemtnos # cantidad de operaciones
num_len=${#length[@]}
num_ops=${#ops[@]}

countexps=1
iterations=1

## Plain
for (( i=0; i<31; i++))
do
    echo ""
    echo "Iteration ${i}"    
    for (( r=0; r<${num_len}; r++))
    do
	for (( o=0; o<${num_ops}; o++))
	do
	    for (( l=0; l<${numalgos}; l++))
	    do
		echo -n -e "\rExperiment ${countexps}"
		
		echo -n $countexps";" >> ${outfile}
		
		perf stat -a -x';' -o ${outfile}.tmp -e \
	    	     power/energy-cores/,power/energy-pkg/,power/energy-ram/,instructions,LLC-loads,LLC-load-misses,LLC-stores,LLC-stores-misses,L1-dcache-loads,L1-dcache-load-misses,L1-dcache-stores,cache-misses,cache-references,branches,branch-misses,cpu-cycles ./${executable[l]} ${length[r]} ${ops[o]} >> ${outfile}
		cut -d';' -f1 ${outfile}.tmp | sed '/#/d' | sed '/^$/d' | paste -s | sed 's/\s\+/;/g' >> ${outfile}
		
		countexps=`expr $countexps + 1`
		
	    done
	done
    done
done
# -a capta todo de los rpocesadores
# imprimir todo por ;

find ${outfile} -type f -exec sed -i 's/<not;counted>/<not-counted>/g' {} \;
find ${outfile} -type f -exec sed -i 's/<not;supported>/<not-supported>/g' {} \;

# not counter indica que no alcanzo a medir
#bash run_exps.sh
#screen -r
#hacer inputs grandes
rm ${outfile}.tmp

