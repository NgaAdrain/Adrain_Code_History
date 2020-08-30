// JavaScript source code
//���������α׷��� 059�й�
//�й�: 201524582
//�̸�: ����
//�߰���� 3�� ���� Ǯ�� JavaScript����

function Create() { //���� ���� ��� ȭ�鿡 ���//
    document.getElementById("DisplayProb").innerHTML = "";
    document.getElementById("Create").setAttribute("style", "display:block");
}
//1�� ���//
function Store() { //Create -> ���� ���� ��ư ������ �߻�//
    var pNum = document.getElementById("ProbNum").value;
    var pText = document.getElementById("ProbText").value;
    var pSel1 = document.getElementById("ProbSel1").value;
    var pSel2 = document.getElementById("ProbSel2").value;
    var pSel3 = document.getElementById("ProbSel3").value;
    var pSel4 = document.getElementById("ProbSel4").value;
    var pSel5 = document.getElementById("ProbSel5").value;
    var pAns = document.getElementById("ProbAns").value;
    var pSimp = document.getElementById("ProbSimp").value;
    if (pNum != '' && pText != '' && pSel1 != '' &&
        pSel2 != '' && pSel3 != '' && pSel4 != '' &&
        pSel5 != '' && pAns != '' && pSimp) {
        var prob = {
            'probNum': pNum, 'probExpl': pText, 'probSel1': pSel1, 'probSel2': pSel2,
            'probSel3': pSel3, 'probSel4': pSel4, 'probSel5': pSel5, 'probAnsw': pAns, 'probSimpExpl': pSimp
        };
        localStorage.setItem('Problem' + pNum, JSON.stringify(prob));
        alert("������ ����Ǿ����ϴ�.");
        textReset();//�Է� text box �ʱ�ȭ//
        makeProbList(pNum);//���� ����Ʈ�� ����ϱ����� ����//
    }
    else {//��ĭ�ִ� ��� �˸�//
        if (pNum == '') alert("���� ��ȣ�� �Է��� �ּ���.");
        else if (pText == '') alert("���� ������ �Է��� �ּ���.");
        else if (pSel1 == '') alert("1�� ������ �Է��� �ּ���.");
        else if (pSel2 == '') alert("2�� ������ �Է��� �ּ���.");
        else if (pSel3 == '') alert("3�� ������ �Է��� �ּ���.");
        else if (pSel4 == '') alert("4�� ������ �Է��� �ּ���.");
        else if (pSel5 == '') alert("5�� ������ �Է��� �ּ���.");
        else if (pAns == '') alert("���� ��ȣ�� �Է��� �ּ���.");
        else if (pSimp == '') alert("������ ������ ������ �Է��� �ּ���.");
    }
}
//1�� ���//
function textReset() {//�Է� text �ʱ�ȭ//
    document.getElementById("ProbNum").value = '';
    document.getElementById("ProbText").value = '';
    document.getElementById("ProbSel1").value = '';
    document.getElementById("ProbSel2").value = '';
    document.getElementById("ProbSel3").value = '';
    document.getElementById("ProbSel4").value = '';
    document.getElementById("ProbSel5").value = '';
    document.getElementById("ProbAns").value = '';
    document.getElementById("ProbSimp").value = '';
}
//1�� ���//
function makeProbList(number) {//�Է¹��� ������ ��ȣ�� ������ ���� ����ϵ��� ��//
    var field = document.getElementById("DisplayList");
    var pNumber = number;
    var prob = localStorage.getItem('Problem' + pNumber);
    var pSimpScri = JSON.parse(prob).probSimpExpl;
    field.innerHTML += "<p id=\"Prob" + pNumber + "\"> ���� " +
        pNumber + "�� <br>" + pSimpScri + "<br>" +
        "<button onclick=\"Modify(" + pNumber + ")\"> ���� ���� </button>"+
        "<button onclick=\"Remove(" + pNumber + ")\"> ���� ���� </button>" +
        "<button onclick=\"DisplayEachProb(" + pNumber + ")\"> ���� Ǯ�� </button> </p > " ;
}
//===================================================================================//
//1�� ���//
function Display() {//local storage�� ����� ��� ������ ���//
    textReset();//�Է� text box �ʱ�ȭ//
    document.getElementById("Create").setAttribute("style", "display:none");
    var len = localStorage.length;
    if (len == 0) return;
    var field = document.getElementById("DisplayProb");
    if (field.innerHTML!="") field.innerHTML="";
    for (var index = 0; index < len; index++) {//��ü����//
        var probKey = localStorage.key(index);
        var prob = localStorage.getItem(probKey);
        makeProblem(field, prob);//������ ����ϱ����� ����//
    }
}
//2�� ���//
function DisplayEachProb(number) {//���� List���� ������ �������� ���//
    textReset();
    document.getElementById("Create").setAttribute("style", "display:none");
    var field = document.getElementById("DisplayProb");
    var prob = localStorage.getItem("Problem" + number);
    var forCheck = document.getElementById("pN" + number);
    if (forCheck!= null) return;
    makeProblem(field, prob);//������ ����ϱ����� ����//
}
//1��, 2�� ���//
function makeProblem(field, probJSON) {//LocalStorage�� �ִ� ������ �����//
    var pNum = JSON.parse(probJSON).probNum;
    var pText = JSON.parse(probJSON).probExpl;
    var pSel1 = JSON.parse(probJSON).probSel1;
    var pSel2 = JSON.parse(probJSON).probSel2;
    var pSel3 = JSON.parse(probJSON).probSel3;
    var pSel4 = JSON.parse(probJSON).probSel4;
    var pSel5 = JSON.parse(probJSON).probSel5;
    
    var problem = "<p id=\"pN"+ pNum + "\"> Problem #" + pNum + ")<br>" + "���� ���� : " + pText + " <br>"+
        "������ 1 : " + pSel1 + " <br>" +"������ 2 : " + pSel2 + " <br>" +
        "������ 3 : " + pSel3 + " <br>" +"������ 4 : " + pSel4 + " <br>" +
        "������ 5 : " + pSel5 + " <br>" + "�� : <input id=\"Answ" + pNum + "\"type=\"number\" min=\"1\" max=\"5\" required>" +
        "<br>"+"<button onClick=\"Submit(" + pNum + ")\">���� ����</button> </p>";
    field.innerHTML += problem;
}
//========================================================================//
//2�� ���//
function Submit(number) {//���� Ǯ �� ��/���� ���� Ȯ��//
    var pAns = JSON.parse(localStorage.getItem('Problem' + number)).probAnsw;
    var inp = document.getElementById("Answ" + number).value;
    if (inp == "") {
        alert("���� �Է����ּ���.");
        return;
    }
    if (pAns != inp) alert("����" + number + " Ʋ�����ϴ�! ������ " + pAns + "�����ϴ�.");
    else alert("����"+ number + " �����Դϴ�!");
}
//========================================================================//
//3�� ���//
function Modify(number) {//������ ������ ��//
    var createField = document.getElementById("Create");
    var displayField = document.getElementById("DisplayProb");
    if (displayField.innerHTML != "" || createField.style.display == "none") {
        displayField.innerHTML = ""; //1. ������ ������� ������ �� 2.���� �ʱ�ȭ���� ��
        createField.style.display = 'block';//���� ���� ȭ�� ���
    }
    var prob = localStorage.getItem('Problem' + number);
    document.getElementById("ProbNum").value = JSON.parse(prob).probNum;
    document.getElementById("ProbText").value = JSON.parse(prob).probExpl;
    document.getElementById("ProbSel1").value = JSON.parse(prob).probSel1;
    document.getElementById("ProbSel2").value = JSON.parse(prob).probSel2;
    document.getElementById("ProbSel3").value = JSON.parse(prob).probSel3;
    document.getElementById("ProbSel4").value = JSON.parse(prob).probSel4;
    document.getElementById("ProbSel5").value = JSON.parse(prob).probSel5;
    document.getElementById("ProbAns").value = JSON.parse(prob).probAnsw;
    document.getElementById("ProbSimp").value = JSON.parse(prob).probSimpExpl;
    Remove(number);//Local Stoarge�� �ִ� ���� ����� ������ ����.//
}
//3�� ���//
function Remove(number) {//Local Storage�� �ִ� ���� ��ȣ�� �ش��ϴ� ������ ����.//
    var forDel = document.getElementById("Prob" + number);
    localStorage.removeItem("Problem" + number);
    document.getElementById("DisplayList").removeChild(forDel);//���� listȭ�鿡�� ����//
    if (document.getElementById("DisplayProb").innerHTML != "") {//���� ��� ȭ�鿡�� ����//
        forDel = document.getElementById("pN" + number);
        document.getElementById("DisplayProb").removeChild(forDel);
    }
}
//========================================================================//
function start() {
    document.getElementById("saveButton").addEventListener("click", Store, false);
    document.getElementById("NewProb").addEventListener("click", Create, false);
    document.getElementById("LoadProb").addEventListener("click", Display, false);
    if (localStorage.length != 0) {//localstorage�� ������ ������ ������� ������
        for (var index = 0; index < localStorage.length; index++) {
            var pKey = localStorage.key(index);
            var pJSON = localStorage.getItem(pKey);
            var numOfProb = JSON.parse(pJSON).probNum;
            makeProbList(numOfProb);//�̸� ���� list�� �߰��ؼ� �ҷ��� �� �ֵ��� �Ѵ�.//
        }
    }
}
window.addEventListener("load", start, false);