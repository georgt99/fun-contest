#include <testlib.h>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    setName("edit distance validator");
    registerTestlibCmd(argc, argv);

    // Use inf (.in file), ouf (submission output) and ans (.ans file)
    // Use quit(_wa, message) or quitf(_wa, format_string, args...) to report wrong answers
    // Exchange _wa by _pe if the format is wrong (should mostly be taken care of by the
    // input functions of ouf)

    int l = inf.readInt(); inf.eoln();
    while(l-->0){
        vector<string> in = split(inf.readString(), ' ');
        string in_typo = in[0];
        string in_correct = in[1];

        int out_len = ouf.readInt();
        string out_seq =  "";
        if(out_len) out_seq = trim(ouf.readLine());
        else ouf.eoln();
        string out_edited = "";

        int ans_len = ans.readInt();
        if(out_len != ans_len) quit(_wa, "invalid sequence length");
        if(out_len != out_seq.size()) quit(_wa, "sequence length and length of sequence do not match");

        if(ans_len == 0){
            ans.eoln();
            continue;
        } else ans.readLine();

        int idx_out_seq = 0, idx_in_typo=0, idx_in_correct = 0;
        while(idx_in_typo < in_typo.size() || idx_in_correct < in_correct.size() || idx_out_seq >= out_seq.size()) {
            while(idx_in_typo < in_typo.size() && idx_in_correct < in_correct.size() && in_typo[idx_in_typo] == in_correct[idx_in_correct]){
                out_edited += in_typo[idx_in_typo];
                idx_in_typo++;
                idx_in_correct++;
            }
            if(idx_out_seq >= out_seq.size()) break;
            char c = out_seq[idx_out_seq++];
            switch(c) {
                case 'd':
                    idx_in_typo++;
                    break;
                case 'i':
                    out_edited += in_correct[idx_in_correct++];
                    break;
                case 'r':
                    if(idx_in_typo >= in_typo.size()) quit(_wa, "invalid sequence");
                    out_edited += in_correct[idx_in_correct++];
                    idx_in_typo++;
                    break;
            }
        }
        if(out_edited != in_correct) quit(_wa, "invalid sequence");
    }
    quit(_ok, "");
}