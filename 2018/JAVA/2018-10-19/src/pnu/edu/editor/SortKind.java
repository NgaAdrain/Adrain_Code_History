package pnu.edu.editor;
import java.util.ArrayList;
import java.util.List;
import pnu.edu.shape.*;

public class SortKind {
	private static List<AreaComputable> tempList; ;
	public static List<AreaComputable> sortList(final List<AreaComputable> comparableList, final SortKindOperator sortKind) { 
		 AreaComputable temp1, temp2;
		 tempList = new ArrayList<AreaComputable>();
		 tempList.addAll(comparableList);
		 switch(sortKind) {
		  case ASCENDING : //size!;
			  for(int count = 0; count <tempList.size(); count++) {
				  int index;
				  for(index = count + 1; index < tempList.size();index++) {
					  if(tempList.get(count).getSize()>tempList.get(index).getSize()) {
						  temp1 = tempList.get(count);
						  temp2 = tempList.get(index);
						  tempList.remove(index);
						  tempList.remove(count); 
						  tempList.add(count,temp2);
						  tempList.add(index,temp1);
					  }
				  }						  
			  }
			  break;
		case DESCENDING : //size!
			  for(int count = 0; count <tempList.size(); count++) {
				  int index;
				  for(index = count + 1; index < tempList.size();index++) {
					  if(tempList.get(count).getSize()<tempList.get(index).getSize()) {
						  temp1 = tempList.get(count);
						  temp2 = tempList.get(index);
						  tempList.remove(index);
						  tempList.remove(count);
						  tempList.add(count,temp2);
						  tempList.add(index,temp1);
					  }
				  }						  
			  }
			  break;
		 
		 }
		 return tempList;
	 }
}
