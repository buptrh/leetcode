for(w in words) {
	mapArticle[w]--;
	if(mapArticle[w]<0) {
		return false;
	}
}