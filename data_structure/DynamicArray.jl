
function parse_line_from_stdin()
    map(x->parse(Int64,x), convert(Array{String,1},split(readline(STDIN), " ")))
end

N,num_query = parse_line_from_stdin()

Arrs = Array{Array{Int64,1},1}(N)
for i in 1:N
    Arrs[i] = Array{Int64,1}(0)
end

lastAns = 0
for i in 1:num_query
    query_type,x,y = parse_line_from_stdin()
    
    if query_type == 0
        ind = mod(x$lastAns,N)+1
        push!(Arrs[ind],y)
    elseif query_type == 1
        ind = mod(x$lastAns,N)+1
        seq = Arrs[ind]
        size = length(seq)
        val = seq[y%size+1]
        println(val)
        lastAns = val
    else
        error("unkown query type")
    end
end

