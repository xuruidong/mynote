
local pairs       = pairs
local ipairs      = ipairs
local ngx         = ngx
local type        = type
local re_sub      = ngx.re.sub
local sub_str     = string.sub
local stringbyte  = string.byte
local table_insert = table.insert
local table_concat = table.concat
local table_new     = table.new
local table_clear   = table.clear
local buffer = require("string.buffer")

local tutil = require("test_util")

-- cmp()

local function init()
    
end

local t_count = 100

local function test_1()
    local s = ""
    for i = 1, t_count do
        s = s .. "a"
    end
    --print("trav1")
    return s
end

local t = table_new(t_count, 0)
local function test_2()
    --local t = {}
    table_clear(t)
    local t_len = 0
    for i = 1, t_count do
        t[i] = i
    end
    return table_concat(t)
    --print("trav2")
end

local buf = buffer.new(400)
local function test_3()
    --local buf = buffer.new(40)
    buf:reset()
    local t_len = 0
    for i = 1, t_count do
        buf:put("a")
    end
    --print("trav2")
    local str = buf:get()
    --buf:free()
    return str
end

init()

tutil.test(test_1, test_2, 5e7)

tutil.test(test_2, test_3, 5e7)

tutil.test(test_3, test_2, 5e7)
