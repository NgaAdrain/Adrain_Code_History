<?php
	include("./prob03_dbsetting.php");
	/*
	//이 코드 정상작동 안함!
	${"body"}.contextmenu( function() {
	return false;
	});
	${"body"}.onselectstart( function() {
	return false;
	});
	${"body"}.ondragstart( function() {
	return false;
	});
	*/
	$ProbNum = $_POST['ProbNum'];
	$ProbText = $_POST['ProbText'];
	$ProbSel1 = $_POST['ProbSel1'];
	$ProbSel2 = $_POST['ProbSel2'];
	$ProbSel3 = $_POST['ProbSel3'];
	$ProbSel4 = $_POST['ProbSel4'];
	$ProbSel5 = $_POST['ProbSel5'];
	$ProbAns = $_POST['ProbAns'];
	$ProbSimp = $_POST['ProbSimp'];
	//form으로 부터 입력받은 값 확인작업
	echo "ProbNum = $ProbNum, ProbText = $ProbText, ProbSel1 = $ProbSel1,";
	echo "ProbSel2 = $ProbSel2,ProbSel3 = $ProbSel3, ProbSel4 = $ProbSel4,";
	echo "ProbSel5 = $ProbSel5,ProbAns = $ProbAns, ProbSimp = $ProbSimp";
	//삽입전 중복을 방지하기위해 기존에 존재하면 삭제//
	$query = 
		"DELETE FROM ".TABLE_NAME." WHERE EXISTS(SELECT * FROM ".TABLE_NAME." WHERE ProbNum = $ProbNum);";
	if (mysqli_query($conn,$query)){//1. 여기 실수했었음(query를 사용안하고 sql로 넣었음(변수명 실수))
		echo "Table ".TABLE_NAME." deleted successfully";
	}
	else{
		echo "Table ".TABLE_NAME." not inserted";
	}
	//데이터삽입//
	$query ="INSERT INTO ".TABLE_NAME." (ProbNum ,ProbText ,ProbSel1 ,ProbSel2 ,ProbSel3 ,ProbSel4 ,ProbSel5 ,ProbAns ,ProbSimp) 
			VALUES ($ProbNum,'$ProbText','$ProbSel1','$ProbSel2','$ProbSel3','$ProbSel4','$ProbSel5',$ProbAns,'$ProbSimp');
		";
	if (mysqli_query($conn,$query)){//2. 삭제와 삽입을 동시에 시도함
		echo "Table ".TABLE_NAME." inserted successfully";
	}
	else{
		echo "Table ".TABLE_NAME." not inserted";
	}
		
?>
