#!/usr/bin/env ruby
T = 10
MAX_N = 100_000_000
puts T
1.upto(T) do
  n = rand(MAX_N) + 1
  puts n
end

