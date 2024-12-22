class Solution(object):
    def compress(self, chars):
        """
        :type chars: List[str]
        :rtype: int
        """
        output_str = ""
        current = chars[0]
        count = 0

        for char in chars:
            if char == current:
                count += 1
            else:
                output_str += current + (str(count) if count > 1 else "")
                current = char
                count = 1

        # Handle the last group
        output_str += current + (str(count) if count > 1 else "")

        # Modify chars in-place
        chars[:] = list(output_str)

        # Return the new length
        return len(chars)
