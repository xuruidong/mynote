
local pairs       = pairs
local ipairs      = ipairs
local ngx         = ngx
local type        = type
local re_sub      = ngx.re.sub
local sub_str     = string.sub
local stringbyte  = string.byte


-- cmp()
local arr = {}
local function prepare_data()
    for i = 1, 1000 do
        arr[i] = i
    end
end


local function trav_ipairs()
    local a = 0
    for _,v in ipairs(arr) do
        a = v
    end
end


local function trav_2()
    local a = 0
    for i = 1, #arr do
        a = arr[i]
    end
end


local function ipairs_test()
    local N = 5e5
    prepare_data()
    ngx.update_time()
    local begin = ngx.now()
    for i = 1, N do
    	
    	trav_ipairs()
    end
    
    ngx.update_time()
    local time_end = ngx.now()
    
    for i = 1, N do
    	trav_2()
    	--print(msg)
    end
    
    ngx.update_time()
    local time_end2 = ngx.now()
    print("time1=", time_end - begin, " tim2=", time_end2-time_end)
    
end

ipairs_test()
