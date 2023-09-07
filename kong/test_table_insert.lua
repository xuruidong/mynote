
local pairs       = pairs
local ipairs      = ipairs
local ngx         = ngx
local type        = type
local re_sub      = ngx.re.sub
local sub_str     = string.sub
local stringbyte  = string.byte
local table_insert = table.insert

local tutil = require("test_util")

-- cmp()

local function init()
    
end

local t_count = 10000

local function test_1()
    local t = {}
    for i = 1, t_count do
        table_insert(t, "a")
    end
    --print("trav1")
end


local function test_2()
    local t = {}
    local t_len = 0
    for i = 1, t_count do
        t_len = t_len + 1
        table_insert(t, t_len, "a")
    end
    --print("trav2")
end




init()

tutil.test(test_1, test_2, 5e3)
