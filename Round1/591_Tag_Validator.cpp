class Solution {
public:
    bool isValid(string code) {
    	if(code.size() == 0) {
    		return true;
    	}
    	// cout<<1<<code<<"!"<<endl;
        if(code[0] != '<' && code[code.size()-1] != '>') {
        	return false;
        }
        int pos = code.find(">", 0);
        string TAG_NAME = code.substr(1, pos-1);
    	// cout<<2<<endl;
        if(TAG_NAME.size() <= 0 || TAG_NAME.size() > 9) {
        	return false;
        }
    	// cout<<3<<TAG_NAME<<endl;
        for(int i = 0; i < TAG_NAME.size(); i++) {
        	if(TAG_NAME[i] > 'Z' || TAG_NAME[i] < 'A') {
        		return false;
        	}
        }
    	// cout<<4<<endl;
        string lastTag = "</" + TAG_NAME + ">";
        int tagend = code.rfind(lastTag);
        if(tagend < 0 ||  tagend != code.size() - lastTag.size()) {
        	cout<<"!!!" << tagend<<". " << code.size() - lastTag.size()<< endl;
        	return false;
        }
        // cout<<5<<endl;
        bool ret = true;
        string TAG_CONTENT = code.substr(TAG_NAME.size() + 2, code.size() - lastTag.size() - TAG_NAME.size() - 2);

        // cout<<"Name:" << TAG_NAME << " | lastTag:" << lastTag <<  " | " << TAG_CONTENT << endl;
    	 pos = 0;
    	int prePos = 0;
    	int posEnd = 0, posCD = 0, posCDEnd = 0;
    	while(prePos < TAG_CONTENT.size() ) {
    		pos = TAG_CONTENT.find("<" , prePos);
    		if(pos < 0) {
    			break;
    		}

    		posEnd = TAG_CONTENT.find(">", pos);
    		posCD = TAG_CONTENT.find("<![CDATA[", prePos);
    		posCDEnd = TAG_CONTENT.find("]]>", posCD);
    		// cout<< pos << "  " << posEnd << "  " << posCD << "  " << posCDEnd << endl;
    	
	    	if(posEnd < 0) {
	    		return false;
	    	}
	    	if(pos != posCD) {
	    		string newTagName = TAG_CONTENT.substr(pos+1, posEnd - pos-1);

	    		// cout<<"newTagName"<<newTagName<<endl;
	    		int newpos = pos;
	    		do {
	    			newpos = TAG_CONTENT.find( "</" + newTagName + ">", newpos);
		    		if(newpos < 0) {
		    			break;
		    		}
		    		// cout<<"newpos" << newpos << "  " << pos<< "  " << newpos + newTagName.size() + 3endl;
		    		ret = isValid(TAG_CONTENT.substr(pos, newpos + newTagName.size() + 3 - pos));
		    		newpos = newpos + newTagName.size() + 3;
	    		// cout<<newpos<< TAG_CONTENT.substr(newpos) << endl;
	    		} while(newpos >= 0 && !ret);
	    		if(!ret || newpos < 0) {
	    			return false;
	    		}
	    		prePos = newpos;
	    	} else {
	    		if (posCDEnd < 0) {
	    			return false;
	    		}
	    		prePos = posCDEnd + 3;
	    	}
    	}

        return ret;
    }
};