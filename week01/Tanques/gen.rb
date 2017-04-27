#!/usr/bin/env ruby
n = rand(1000)
puts n
n.times do
  x = rand(2000) - 1000
  y = rand(2000) - 1000
  puts "#{x} #{y}"
end
