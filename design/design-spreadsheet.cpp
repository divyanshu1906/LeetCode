class Spreadsheet {
private:
    vector<vector<int>>spreadSheet;

    pair<int, int>parseCell(string cell){
        int col = cell[0]-'A';
        int row = stoi(cell.substr(1))-1;
        return {row, col};
    }

    int evaluateFormula(string &formula){
        string left, right;
        int opPos = formula.find('+');
        
        if (opPos != string::npos) {
            left = formula.substr(1, opPos - 1);   
            right = formula.substr(opPos + 1);    
        }
        else {
            return 0; 
        }

        int val1 = isdigit(left[0]) ? stoi(left) : getCellValue(left);
        int val2 = isdigit(right[0]) ? stoi(right) : getCellValue(right);
        return val1 + val2;
    }

public:
    
    Spreadsheet(int rows) {
        spreadSheet.resize(rows, vector<int>(26, 0));
    }
    
    void setCell(string cell, int value) {
        auto[row, col] = parseCell(cell);
        spreadSheet[row][col] = value;
    }
    
    void resetCell(string cell) {
        auto[row, col] = parseCell(cell);
        spreadSheet[row][col] = 0;
    }

    int getCellValue(string cell){
        auto[row, col] = parseCell(cell);
        return spreadSheet[row][col];
    }
    
    int getValue(string formula) {
        if(formula[0]=='='){
            return evaluateFormula(formula);
        }
        else return stoi(formula);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */