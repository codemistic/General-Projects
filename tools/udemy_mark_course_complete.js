snaps = document.getElementsByClassName("js-panel-toggler")
for(let x of snaps) {
  if(x.attributes['aria-expanded'].value.localeCompare("false") == 0) {
      x.click()
  }
}

ticks = document.getElementsByClassName("curriculum-item-link--progress-toggle--1CMcg")
for(let x of ticks) {
  if(!document.getElementById(x.attributes['for'].value).checked) {
      x.click()
  }
}