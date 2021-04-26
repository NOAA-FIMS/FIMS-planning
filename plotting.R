require(plotly)
require(nmfspalette)
require(dplyr)

schematic <- data.frame("Effort"=c(rep(1,4),rep(2,4)), "Impact"=rep(c(1,2),4), "Compatibility"=rep(c(1,1,2,2),2))
schematic$Priority <- c("Quick Win","Easy, Consistent, Low Impact","Easy, New, High Impact","Easy, Inconsisent, Low Impact","Hard but Important and Impactful","Hard but Important for Consistency","Hard, New, High Impact","Thankless Task")
schematic <- schematic %>% mutate("Priority_num"=Effort + Impact + Compatibility)
#schematic$am <- as.factor(mtcars$am)

fig <- plot_ly(schematic, x = ~Effort, y = ~Impact, z = ~Compatibility, color=~Priority, 
               colors=nmfs_palette("regional web")(6))
fig <- fig %>% add_markers()
fig

htmlwidgets::saveWidget(fig, file="Priority.html")
