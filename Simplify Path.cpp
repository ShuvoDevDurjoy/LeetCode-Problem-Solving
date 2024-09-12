class Solution {
public:
    string simplifyPath(string path) {
        string simplifiedPath = "";
    int size = path.length();
    for (int i = 0; i < size; ++i)
    {
        if (path[i] == '/')
        {
            int j = i + 1;
            while (j < size && path[j] == path[i])
            {
                j++;
            }
            i = j - 1;
            simplifiedPath += "/";
        }
        else
        {
            simplifiedPath += path[i];
        }
    }

    size = simplifiedPath.length();
    string t = "";
    stack<string> paths;

    for (int i = simplifiedPath[size - 1] == '/' ? size - 2 : size - 1; i >= 0; --i)
    {
        if (simplifiedPath[i] == '/')
        {
            reverse(t.begin(), t.end());
            paths.push(t);
            t = "";
        }
        else
        {
            t += simplifiedPath[i];
        }
    }
    stack<string> dup;
    while (!paths.empty())
    {
        if (paths.top() == ".")
        {
            paths.pop();
        }
        else if (paths.top() == "..")
        {
            paths.pop();
            if (!dup.empty())
            {
                dup.pop();
            }
        }
        else
        {
            dup.push(paths.top());
            paths.pop();
        }
    }

    stack<string> mainPath;
    while (!dup.empty())
    {
        mainPath.push(dup.top());
        dup.pop();
    }
    simplifiedPath = "/";
    while (!mainPath.empty())
    {
        simplifiedPath += mainPath.top();
        mainPath.pop();
        if (!mainPath.empty())
        {
            simplifiedPath += "/";
        }
    }
    return simplifiedPath;
    }
};
