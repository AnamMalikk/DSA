class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int sentenceLength = 0;
        int left = 0, right = 0;          // window brackets

        while (right < words.size()) {

            // If adding words[right] exceeds maxWidth, justify and create the current sentence and add to ans
            if (sentenceLength + words[right].size() > maxWidth) {
                right--; // remove the word that caused overflow
                string sentence;

                // More than one word → evenly distribute spaces
                if (left < right) {
                    int spacesToDistribute = maxWidth - sentenceLength + (right - left + 1);
                    int gaps = right - left;
                    int baseSpace = spacesToDistribute / gaps;
                    int extraSpace = spacesToDistribute % gaps;

                    while (left < right) {
                        sentence += words[left++];
                        sentence.append(baseSpace, ' ');
                        if (extraSpace > 0) {
                            sentence += ' ';
                            extraSpace--;
                        }
                    }
                }

                // Add the last word of the sentence
                sentence += words[left];

                // Single-word sentence needs to be left aligned, so provide padding in right
                while (sentence.size() < maxWidth) sentence += ' ';

                ans.push_back(std::move(sentence));

                // Move window forward
                left = ++right;
                sentenceLength = 0;
            }

            // Handle the final line (left-aligned)
            if (right == words.size() - 1) {
                string sentence;
                while (left < right) sentence += words[left++] + ' ';
                sentence += words[left];
                while (sentence.size() < maxWidth) sentence += ' ';
                ans.push_back(std::move(sentence)); // Transfer sentance data without copying, hence optimising performance more
                break;
            }

            // Extend window
            sentenceLength += words[right].size() + 1; // include the size/ length for a space too
            right++;
        }

        return ans;
    }
};
