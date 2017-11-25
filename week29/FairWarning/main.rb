#!/usr/bin/env ruby

test_cases = STDIN.gets.chomp.to_i

1.upto(test_cases) do |tc|
  tokens = STDIN.gets.chomp.split
  size = tokens[0].to_i
  values = tokens[1..-1].map(&:to_i).sort
  g = values[1] - values[0]
  values.each_with_index do |_, i|
    next if i < 2
    g = g.gcd(values[i] - values[i-1])
  end
  ans = values[0] % g
  if ans != 0
    ans = g - ans
  end
  puts "Case ##{tc}: #{ans}"
end
