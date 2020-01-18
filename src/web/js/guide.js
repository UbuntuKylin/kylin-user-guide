require.config({
   paths: {
     "marked": "lib/node_modules/marked/marked.min",
   }
 });
require(['marked'], function (markedSetCustom){

//    alert('add marked');
    var marked = require('marked');
    marked.setOptions({
        renderer: new marked.Renderer(),
        gfm: true,
        tables: true,
        breaks: false,
        pedantic: false,
        sanitize: false,
        smartLists: true,
        smartypants: false
    });

    console.log(marked('I am using __markdown__.'));
 });

//readFile = function (fileName, callback) {
//  var xhr = new XMLHttpRequest();
//  xhr.open('GET', fileName);
//  xhr.onload = function () {
//    if (xhr.responseText != '') {
//      callback(xhr.responseText);
//    }
//  };
//  xhr.send();
//};

function onclickButton(str)
{
//    alert(str)
    console.log(str)
    document.getElementById("mainUI").style.display="none";
    document.getElementById("pageContent").style.display="inline";

    var mdPath = window.guideWebkit.js_getIndexMdFilePath(str)
    var mdDate = window.guideWebkit.js_getIndexMdFileContent(mdPath)
//    alert(mdDate)
    var m2ht = getDocTop(mdPath,mdDate)
    var html = m2ht.html
    var hlist = m2ht.hlist
    var info = m2ht.info
    console.log(html);
    console.log("--------------------------------------hlist");
    console.log(hlist);
    console.log("--------------------------------------info");
    console.log(info);
    var hlist_str = "";
    for (i = 0; i < hlist.length; i++) {
        console.log(hlist[i].type);
        if(hlist[i].type == "h1")
            hlist_str +=  "<h1>\n" + "<a id=" + "list_"+hlist[i].id + " href=#" +hlist[i].id + ">" + hlist[i].text + "</a> \n</h1>" ;
        else if(hlist[i].type == "h2")
            hlist_str +=  "<h2>\n" + "<a id=" + "list_"+hlist[i].id + " href=#" +hlist[i].id + ">" + hlist[i].text + "</a> \n</h2>" ;
        else if(hlist[i].type == "h3")
            hlist_str +=  "<h3>\n" + "<a id=" + "list_"+hlist[i].id + " href=#" +hlist[i].id + ">" + hlist[i].text + "</a> \n</h3>" ;
     }
    console.log(hlist_str);

    document.getElementById("hlist").innerHTML = hlist_str
    document.getElementById("content").innerHTML = html

}

function goBackMainUI()
{
    //alert(str)
    //console.log(str)
    //document.getElementById("mainUI").style.display="inline";
    //document.getElementById("pageContent").style.display="none";
    window.location.href="index.html"
}

function getDocTop(mdFile, mdData) {
    let hlist = [];
    let info = {};
    let html = '';

    let path = mdFile.slice(0, mdFile.lastIndexOf('/') + 1);
    let count = 0;
    let renderer = new marked.Renderer();
    renderer.heading = (text, level) => {
        let id = 'h' + count;
        count++;
        if (level == 1) {
            let [title, logo] = text.split('|');
            logo = path + logo;
            console.log(logo);
            info = { title, logo };
            return '';
        }
        if (level == 2) {
            text = text.split('|')[0];
            console.log(text);
        }
        let type = 'h' + level;
        if (level == 2 || level == 3) {
            hlist.push({ id, text, type });
            console.log(id);
            console.log(text);
            console.log(type);
        }
            return `<${type} id="${id}" text="${text}">${text}</${type}>\n`;
    };
    console.log(path);
    renderer.image = (href, title, text) => {
        let hrefX2 = href;
        if (devicePixelRatio >= 1.5 && href.indexOf('.svg') == -1) {
            let path = href.split('.');
            let ext = path.pop();
            hrefX2 = `${path.join('.')}x2.${ext}`;
        }
        return `<img src="${hrefX2}" data-src="${href}" alt="${text}" />`;
    };
    html = marked(mdData, { renderer }).replace(/src="/g, `$&${path}`);
    return { html, hlist, info };
}
