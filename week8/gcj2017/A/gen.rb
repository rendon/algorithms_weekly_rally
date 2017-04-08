#!/usr/bin/env ruby
W = 16
T = 2 ** W
puts T + 1
0.upto(T) do |n|
  f = '%0' + W.to_s + 'b'
  pancakes = (f % n).gsub('0', '-').gsub('1', '+')
  puts "#{pancakes} #{rand(W) + 1}"
end
