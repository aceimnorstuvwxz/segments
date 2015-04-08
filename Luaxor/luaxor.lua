usage = [[
usage: lua luaxor inputfile mykey [outputfile]
]]

infile = ""
outfile = ""
mykey = ""
key_index = 1
function nextKey()
    local res = mykey.byte(key_index)
    key_index = key_index + 1
    if (key_index > #mykey) then
        key_index = 1
    end
    return res
end
function xor(line, key)
    print (#line)
    local res = ""
    for i = 1, #line, 1 do
        res = string.format("%c",  (line.byte(i)~nextKey()))
        print (res)
    end
    print(res)
    return res
end


function iofile()
    local reader = io.lines(infile)
    local f_out = io.open(outfile, "w")
    local line = reader()
    while line do
        f_out:write(xor(line, mykey))
        line = reader()
    end
    f_out:close()
end

function main()
    print ([[XOR cipher start]])
    if #arg >= 2 then
        infile = arg[1]
        if #arg >= 3 then
            outfile = arg[3]
        else
            outfile = infile..".ot"
        end
        mykey = arg[2]
        print (infile, outfile, mykey)
        iofile()
    else
        print(usage)
    end
    print ([[DONE]])
end

main()