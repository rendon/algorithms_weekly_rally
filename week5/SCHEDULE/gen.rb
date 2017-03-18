#!/usr/bin/env ruby

puts 11 * 2 ** 10
0.upto(10) do |k|
  0.upto(2**10 - 1) do |n|
    puts "10 #{k}"
    puts "%010b" % n
  end
end
