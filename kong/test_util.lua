
local ngx = ngx

local _M = {}


local function perf_test(func1, func2, n)
    local N = n or 5e5
    local test_func1 = func1
    local test_func2 = func2
    ngx.update_time()
    local begin = ngx.now()
    for i = 1, N do
        test_func1()
    end
    
    ngx.update_time()
    local time_end = ngx.now()
    
    for i = 1, N do
    	test_func2()
    end
    
    ngx.update_time()
    local time_end2 = ngx.now()
    print("test count: ", N, ", func1 costs: ", time_end - begin, ", func2 costs: ", time_end2-time_end)
end

_M.test = perf_test

return _M
