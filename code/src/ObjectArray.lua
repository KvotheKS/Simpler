ObjectArray = setmetatable({},
    {
        __shl = function(tbl, obj)
            tbl[#tbl+1] = obj
            return tbl
        end,

        __sub = function(tbl, obj)
            cnt = #tbl
            for i = 1, cnt do
                if obj == tbl[i] then
                    table.remove(tbl, i)
                    return tbl
                end
            end
            return tbl
        end
    }
)

function ObjectArray:ClearState()
    local cnt = #self
    for i = 1, cnt do
        self[i] = nil
    end
end

function ObjectArray:UpdateGameObjects(dt)
    local cnt = #self
    for i = 1, cnt do 
        self[i]:Update(dt) 
        self[i]:UpdateComponents(dt)
    end
end

function ObjectArray:RenderGameObjects()
    local cnt = #self
    for i = 1, cnt do 
        self[i]:Render() 
        self[i]:RenderComponents()
    end
end

function ObjectArray:AddGameObject(obj)
    self[#self+1]=obj
end

function ObjectArray:RemoveGameObject(obj)
    local cnt = #self
    for i = 1, cnt do
        if self[i] == obj then
            table.remove(self, i)
            return
        end
    end
end

function ObjectArray:DeadGameObjects()
    local i, cnt = 1, #self
    while i <= cnt and cnt > 0 do
        if self[i]:IsDead() then
            table.remove(self, i)
            i = i-1
            cnt = cnt-1
        end
    end
end