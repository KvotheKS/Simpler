ObjectArray = setmetatable({}, {})

function ClearState()
    cnt = #ObjectArray
    for i = 1, cnt do
        ObjectArray[i] = nil
    end
end

function UpdateGameObjects(dt)
    cnt = #ObjectArray
    for i = 1, cnt do 
        ObjectArray[i]:Update(dt) 
        ObjectArray[i]:UpdateComponents(dt)
    end
end

function RenderGameObjects()
    cnt = #ObjectArray
    for i = 1, cnt do 
        ObjectArray[i]:Render() 
        ObjectArray[i]:RenderComponents()
    end
end

function AddGameObject(obj)
    ObjectArray[#ObjectArray+1]=obj
end

function RemoveGameObject(obj)
    cnt = #ObjectArray
    for i = 1, cnt do
        if ObjectArray[i] == obj then
            table.remove(ObjectArray, i)
            return
        end
    end
end

function DeadGameObjects()
    i, cnt = 1, #ObjectArray
    while i <= cnt and cnt > 0 do
        if ObjectArray[i]:IsDead() then
            table.remove(ObjectArray, i)
            i -= 1
            cnt -= 1
        end
    end
end