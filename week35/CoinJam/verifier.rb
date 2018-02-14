#!/usr/bin/env ruby

File.readlines(ARGV[0]).map(&:chomp).each do |line|
  next if line.start_with?("Case")
  tokens = line.split(" ")
  str = tokens[0]
  divisors = tokens[1..-1].map(&:to_i)
  2.upto(10) do |base|
    num = str.to_i(base)
    divisor = divisors[base-2]
    if num % divisor != 0
      raise "line: #{line} base = #{base} divisor = #{divisor}"
    end
    if divisor == 1 || divisor == num
      raise "Non-trivial divisor: str = #{str} base = #{base} divisor = #{divisor}"
    end
  end
end
