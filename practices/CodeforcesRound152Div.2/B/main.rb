#!/usr/bin/env ruby
require 'bigdecimal'
n = STDIN.gets.chomp.to_i
x = 10 ** (n - 1) / 210

a = x * 210
b = (x + 1) * 210
if a.to_s.length == n && a > 0
  puts a
elsif b.to_s.length == n && b > 0
  puts b
else
  puts -1
end
