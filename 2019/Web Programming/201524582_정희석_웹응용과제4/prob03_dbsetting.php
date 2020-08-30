<?php
	define("DB_IP","164.125.36.45");
	define("DB_ID","201524582");
	define("DB_PSWD","a123456b");
	define("TABLE_NAME","problemSets");
	//============================//
	//복사방지//작동안함!//
	/*
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
	//============================//
	$conn = mysqli_connect("localhost","root","",DB_ID);
	//$conn = mysqli_connect(DB_IP,DB_ID,DB_PSWD,DB_ID);//학교서버용
	
	if(!$conn){
		error("DB_ERROR");
		exit;
	}

	$sql = "
		CREATE TABLE IF NOT EXISTS ".TABLE_NAME."(
		ProbNum int ,
		ProbText VARCHAR(255),
		ProbSel1 VARCHAR(50),
		ProbSel2 VARCHAR(50),
		ProbSel3 VARCHAR(50),
		ProbSel4 VARCHAR(50),
		ProbSel5 VARCHAR(50),
		ProbAns int,
		ProbSimp VARCHAR(255)
		);";
	if (mysqli_query($conn,$sql)){
		echo "Table ".TABLE_NAME." created successfully";
	}
	else{
		echo "Table ".TABLE_NAME." not created";
	}
?>
