// My version
class Solution {
public:
    struct Expr {
        Expr* parent;
        char op;
        vector<Expr*> operands;
        Expr(char op, Expr* parent = nullptr) : op(op), parent(parent), operands() {}  
    };

    bool evalExpr(Expr* root) {
        if (root->op == 't') return true;
        if (root->op == 'f') return false;
        if (root->op == '&') {
            bool result = true;
            for (auto op : root->operands)
                result &= evalExpr(op);
            return result;
        }
        if (root->op == '|') {
            bool result = false;
            for (auto op : root->operands)
                result |= evalExpr(op);
            return result;
        }
        if (root->op == '!') 
            return !evalExpr(root->operands[0]);
        return false;
    }

    bool parseBoolExpr(string expression) {
        Expr* root = new Expr(expression[0]);
        Expr* curr_root = root;
        int i = 2, left = 0, right = 0;
        while (i < expression.size()) {
            if (expression[i] == 't' || expression[i] == 'f')
                curr_root->operands.push_back(new Expr(expression[i], curr_root));
            else if (expression[i] == '&' || expression[i] == '|' || expression[i] == '!') {
                curr_root->operands.push_back(new Expr(expression[i], curr_root));
                curr_root = curr_root->operands.back();
                ++i;
            }
            else if (expression[i] == ')')
                curr_root = curr_root->parent;          
            
            ++i;
        }

        return evalExpr(root);
    }

    
};

// Community version
class Solution {
public:
    char evaluate(char a, char b, char op)
    {
        bool x=(a=='t')?true:false;
        bool y=(b=='t')?true:false;
        switch (op)
        {
            case '|':
               x=x|y;
               break;
            case '&':
               x=x&y;
               break;
        }
        return x?'t':'f';
    }
    bool parseBoolExpr(string expression) {
        stack<char>st;
        stack<char>op;
        int n=expression.length();
        for(int i=0;i<n;i++)
        {
            char c=expression[i];
            if(c=='|'||c=='&'||c=='!')
                op.push(c);
            else if(c=='('||c=='t'||c=='f')
                st.push(c);
            else if(c==')')
            {
                char opera=op.top();
                op.pop();
                char a=st.top();
                st.pop();
                if(opera!='!') {
                    while(!st.empty()&&st.top()!='(') {
                        a=evaluate(a,st.top(),opera);
                        st.pop();
                    }
                }
                else
                    a=(a=='t')?'f':'t';

                st.pop();
                st.push(a);
            }
        }
        return st.top()=='t'?true:false;
    }
};
