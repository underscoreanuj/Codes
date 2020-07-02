class Solution
{
public:
    int lengthLongestPath(string input)
    {
        istringstream paths(input);
        string path;
        int max_path_len = 0, depth = 0;

        unordered_map<int, int> depth_map;

        while (getline(paths, path))
        {
            depth = path.find_last_of("\t");
            depth = (depth == string::npos) ? 0 : depth + 1;

            if (path.find(".") != string::npos)
            { // it is a file
                max_path_len = max(max_path_len, int(depth_map[depth] + path.length()));
            }
            else
            {
                depth_map[depth + 1] = depth_map[depth] + path.length() - depth;
            }
        }

        return max_path_len;
    }
};