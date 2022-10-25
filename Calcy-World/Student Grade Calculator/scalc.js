const calcy = () => {
    let s1 = document.getElementById("s1").value;
    let s2 = document.getElementById("s2").value;
    let s3 = document.getElementById("s3").value;
    let s4 = document.getElementById("s4").value;
    let s5 = document.getElementById("s5").value;

    let totalGrades =
        parseFloat(s1) +
        parseFloat(s2) +
        parseFloat(s3) +
        parseFloat(s4) +
        parseFloat(s5);
    alert(totalGrades);

    let prcnt = parseFloat(totalGrades / 500) * 100;
    alert(prcnt);

    if (prcnt <= 100 && prcnt >= 80) {
        grade = "A";
    } else if (prcnt < 80 && prcnt >= 60) {
        grade = "B";
    } else if (prcnt < 60 && prcnt >= 35) {
        grade = "c";
    } else if (prcnt < 35 && prcnt >= 20) {
        grade = "D";
    } else if (prcnt < 20) {
        grade = "E";
    }

    if (prcnt >= 21) {
        document.getElementById(
            "showData"
        ).innerHTML = `Out of 500 your total is <b>${totalGrades}</b>  and percentage is <b>${prcnt}%</b> <br> Your Grade is ${grade}. You are Pass.`;
    } else {
        document.getElementById(
            "showData"
        ).innerHTML = `Out of 500 your total is <b>${totalGrades}</b> and percentage is <b>${prcnt}%</b> <br> Your Grade is ${grade}. You are fail.`;
    }
};
